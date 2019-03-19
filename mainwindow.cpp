#include <algorithm>
#include "mainwindow.h"
#include "ui_mainwindow.h"

//QMessageBox::warning(nullptr,"Warning", "Warning message text");
//QMessageBox::information(nullptr, "Information", "Information message text");
//QMessageBox::critical(nullptr, "Critical", "Critical message text");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(680, 340);          // Устанавливаем размеры окна приложения
    this->setPosition(*this, parent);
    this->setWindowTitle(FULL_PROGRAMM_NAME);

    ui->leBaseFile->setText(file_name_base);
    ui->lbFrom->setEnabled(false);
    ui->lbTo->setEnabled(false);
    ui->cbFrom->setEnabled(false);
    ui->cbTo->setEnabled(false);
    Run();            
}

void MainWindow::Run()
{
    // Подключаемся к базе
    if (! CheckBase())
    {
        QMessageBox::warning(nullptr,"Warning", "Подключение к БД не удалось, выберите файл БД вручную");
        ui->widget->xAxis->setRange(MIN_X, MAX_X);
        ui->widget->yAxis->setRange(MIN_Y, MAX_Y);
    }
    else
    {
        // Читаем из БД
        GetDataFromBase();
        //Установим область, которая будет показываться на графике
        if ((max_x > EPSILON) || (min_x < EPSILON) || (max_y > EPSILON) || (min_y < EPSILON))
        {
            ui->widget->xAxis->setRange(min_x - 10, max_x + 10);//Для оси Ox
            ui->widget->yAxis->setRange(min_y - 10, max_y + 10);//Для оси Oy
        }
        else {
            ui->widget->xAxis->setRange(MIN_X, MAX_X);
            ui->widget->yAxis->setRange(MIN_Y, MAX_Y);
        }
        // Рисуем карту станции
        PaintMap();
    }
    if (map.EdgesEmpty())
    {
        ui->lbFrom->setEnabled(false);
        ui->lbTo->setEnabled(false);
        ui->cbFrom->setEnabled(false);
        ui->cbTo->setEnabled(false);
        ui->pbFindRoute->setEnabled(false);
        ui->cbFrom->clear();
        ui->cbTo->clear();
    }
    else {
        for (auto OnePoint: map.getPoints())
        {
            ui->cbFrom->addItem(QString::number(OnePoint->id));
            ui->cbTo->addItem(QString::number(OnePoint->id));
        }
        ui->lbFrom->setEnabled(true);
        ui->lbTo->setEnabled(true);
        ui->cbFrom->setEnabled(true);
        ui->cbTo->setEnabled(true);
        ui->pbFindRoute->setEnabled(true);
        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    }
    ui->widget->replot();
}

bool MainWindow::CheckBase()
{
    if (! QFile::exists(file_name_base))
    {
        QMessageBox::warning(nullptr, PROGRAMM_NAME, "Файл БД не доступен! \n Для продолжения укажите файл БД.");
        file_name_base = GetFileNameBase();
        ui->leBaseFile->setText(file_name_base);
    }
    dbs.setDatabaseName(file_name_base);
    if (! dbs.open())
    {
       qWarning() << "Can't open";
//       QMessageBox::warning(nullptr, PROGRAMM_NAME, "Соединение с БД не установлено!");
    }
    else
    {
        query.prepare("SELECT name, sql FROM sqlite_master WHERE type='table'");
        query.exec();
        query.last();
        int countRows = 0;
        countRows = query.at() + 1;
        if (countRows <= 0)
        {
           qCritical() << "corrupt or invalid sqlite file";
//           QMessageBox::critical(nullptr, PROGRAMM_NAME, "Файл БД поврежден или или недействителен!");
        }
        else
        {
            query.first();
            countRows = 0;
            QString tables = "Found next tables: ";
            do {
                ++countRows;
                tables += query.value(0).toString() + " ";
            } while (query.next());
            qInfo() << countRows << tables;
            return true;
        }
    }
    return false;
}

void MainWindow::GetDataFromBase()
{
    {
    Profiler prfr("Read GEO_POINTS:");
        query.prepare("select * from GEO_POINT order by ID");
        query.exec();
        while (query.next())
        {
            PointOnMap *point = new PointOnMap;
            point->id = query.value(0).toInt();
            point->x = query.value(1).toFloat();
            point->y =query.value(2).toFloat();
            map.addOnePoint(point);
            max_x = std::max(max_x, query.value(1).toDouble());
            min_x = std::min(min_x, query.value(1).toDouble());
            max_y = std::max(max_y, query.value(2).toDouble());
            min_y = std::min(min_y, query.value(2).toDouble());
        }
    }
    {
        Profiler prfr("Read GEO_LINES:");
        query.prepare("select ID, ID_GEO_POINT_START, ID_GEO_POINT_END, LENGHT from GEO_LINE order by ID");
        query.exec();
        while (query.next())
        {
            Edge *OneEdge = new Edge;
            OneEdge->id = query.value(0).toInt();
            OneEdge->start = map.getOnePoint(query.value(1).toInt());
            OneEdge->end = map.getOnePoint(query.value(2).toInt());
            OneEdge->length = query.value(3).toInt();
            map.addOneEdge(OneEdge);
        }
    }
    {
        Profiler prfr("Find Parents:");
        map.findParents();
    }
}

void MainWindow::PaintMap()
{
    {
        Profiler prfr("Paints station map");
        QVector<double> x(2), y(2);
        ui->widget->clearGraphs();//Если нужно, то очищаем все графики
//        ui->widget->replot();
        int count = 0;
        for (auto OneEdge: map.getEdges())
        {
            x[0] = static_cast<double>(OneEdge->start->x);
            y[0] = static_cast<double>(OneEdge->start->y);
            x[1] = static_cast<double>(OneEdge->end->x);
            y[1] = static_cast<double>(OneEdge->end->y);
            ui->widget->addGraph();
            ui->widget->graph(count)->setData(x, y);
            count++;
        }
        ui->widget->replot();
    }
}


void MainWindow::setPosition(QWidget & current, QWidget * parrent)
{
    int left, top;
    if ( parrent ){
        left = parrent->pos().x() + (parrent->frameGeometry().width() / 2) -
               (current.frameGeometry().width() / 2);
        top = parrent->pos().y() + (parrent->frameGeometry().height() / 2) -
              (current.frameGeometry().height() / 2);
    } else{
        left = (qApp->desktop()->width() / 2) - (current.frameGeometry().width() / 2);
        top = (qApp->desktop()->height() / 2) - (current.frameGeometry().height() / 2);
    }
    current.setGeometry(QRect(left, top,
               current.frameGeometry().width(),
               current.frameGeometry().height()));
}

bool MainWindow::MessBox(QString message)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(PROGRAMM_NAME);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Save:
            return false;
        case QMessageBox::Ok:
            return true;
        default:
            return false;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if (MessBox("Завершить работу?"))
    {
        qInfo() << "Programm closed";
        event->accept();
    }
}

MainWindow::~MainWindow()
{  
    delete ui;
    qDebug() << "d-tor MainWindow ";
}

QString MainWindow::GetFileNameBase()
{
    QString str = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.db");
    return str;
}

void MainWindow::on_tbBaseFile_clicked()
{
    file_name_base = GetFileNameBase();
    if (dbs.isOpen())
    {
        dbs.close();
        dbs.removeDatabase(QSqlDatabase::defaultConnection);
    }
    dbs.setDatabaseName(file_name_base);
    ui->leBaseFile->setText(file_name_base);
    map.ClearData();
//    ui->widget->close();
//    ui->setupUi(this);
//    ui->widget->clearPlottables();
//    int count = ui->widget->itemCount();
//    for (int i = 0; i < count; i++)
//        ui->widget->removeItem(i);
    ui->widget->clearGraphs();//Если нужно, то очищаем все графики
//    ui->widget->replot();
//    ui->widget->clearGraphs();
    Run();
}

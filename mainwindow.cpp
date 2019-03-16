#include "mainwindow.h"
#include "ui_mainwindow.h"

//QMessageBox::warning(0,"Warning", "Warning message text");
//QMessageBox::information(0, "Information", "Information message text");
//QMessageBox::critical(0, "Critical", "Critical message text");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(680, 340);          // Устанавливаем размеры окна приложения
    this->setPosition(*this, parent);
    this->setWindowTitle(version);

    ui->leBaseFile->setText(file_name_BD);

    // Подключаемся к базе
    if (! QFile::exists(file_name_BD))
    {
        QMessageBox::warning(0, version, "Файл БД не доступен! \n Для продолжения укажите файл БД.");
        file_name_BD = getFilenameBD();
        ui->leBaseFile->setText(file_name_BD);
    }
    dbs.setDatabaseName(file_name_BD);
    if (! dbs.open())
    {
       qWarning() << "Can't open";
       QMessageBox::warning(0, version, "Соединение с БД не установлено!");
    }
    else
    {
        query.prepare("SELECT name, sql FROM sqlite_master WHERE type='table'");
        query.exec();
        int countRows = 0;
        query.last();
        countRows = query.at() + 1;
        if (countRows <= 0)
        {
           qCritical() << "corrupt or invalid sqlite file";
           QMessageBox::critical(0, version, "Файл БД поврежден или или недействителен!");
        }
        else
        {
            query.first();
            countRows = 0;
            qInfo() << "Found next tables:";
            do {
                ++countRows;
                QString name = query.value(0).toString();
                qInfo() << countRows << "table name =" << name;

            } while (query.next());
        }
    }

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(MIN_X, MAX_X);//Для оси Ox
    ui->widget->yAxis->setRange(MIN_Y, MAX_Y);//Для оси Oy

    // TODO:
    // Процедура чтения из БД и перерисовки

    StationMap map;
    {
        Profiler x("Read GEO_POINTS");
        query.prepare("select * from GEO_POINT order by ID");
        query.exec();
        while (query.next())
        {
            PointOnMap point;
            point.id = query.value(0).toInt();
            point.x = query.value(1).toFloat();
            point.y =query.value(2).toFloat();
            map.addPoint(point);
        }
    }
    {
        Profiler x("Read GEO_LINES");
        query.prepare("select ID, ID_GEO_POINT_START, ID_GEO_POINT_END, LENGHT from GEO_LINE order by ID");
        query.exec();
        while (query.next())
        {
            Edge OneEdge;
            OneEdge.id = query.value(0).toInt();
            OneEdge.start = map.getPoint(query.value(1).toInt());
            OneEdge.end = map.getPoint(query.value(2).toInt());
            OneEdge.length = query.value(3).toInt();
            map.addEdge(OneEdge);
        }
    }
    {
        Profiler x("findParents");
        map.findParents();
    }
    std::cout << std::endl;

//    QVector<double> x(2), y(2); //Массивы координат точек

//    ui->widget->clearGraphs();//Если нужно, то очищаем все графики
//    int count = 0;
//    for (auto OneLine: GeoLines)
//    {
//        qDebug() << "id = " << OneLine.id << " x1 = " << OneLine.x1 << "y1 = " << OneLine.y1 << " x2 = " << OneLine.x2 << "y2 = " << OneLine.y2;
//        x[0] = OneLine.x1;
//        y[0] = OneLine.y1;
//        x[1] = OneLine.x2;
//        y[1] = OneLine.y2;
//        //Добавляем один график в widget
//        ui->widget->addGraph();
//        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
//        ui->widget->graph(count)->setData(x, y);
//        count++;
//    }

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
    msgBox.setWindowTitle(version);
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
}

QString MainWindow::getFilenameBD()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.db");
    return str;
}

void MainWindow::on_tbBaseFile_clicked()
{
    file_name_BD = getFilenameBD();
    dbs.setDatabaseName(file_name_BD);
    ui->leBaseFile->setText(file_name_BD);
    dbs.open();
    // TODO:
    // Процедура чтения из БД и перерисовки
}

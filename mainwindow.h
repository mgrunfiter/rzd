#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtWidgets>
#include <QDialog>
#include <iostream>
#include <QDebug>
#include <QCloseEvent>
#include <vector>
#include <algorithm>
#include "logger.h"
#include "defines.h"
#include "stationmap.h"
#include "profiler.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void Run();
    bool CheckBase();
    void GetDataFromBase();
    void PaintMap();
    void PaintGraph(std::vector<Edge *> Edges, int LineWidth=1, bool all=true);
    void SetCurrentColor(Qt::GlobalColor Color);
    Qt::GlobalColor GetCurrentColor();
    QString GetFileNameBase();
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
    void setPosition(QWidget & current, QWidget * parrent);

private slots:
    void on_tbBaseFile_clicked();
    void on_leBaseFile_returnPressed();
    void on_pbFindRoute_clicked();

private:
    void ReOpen();
    void SetLabel(Edge *Edge, bool IsStart=true);
    Ui::MainWindow *ui;
    bool MessBox(QString message);
    QSqlDatabase dbs;
    QSqlQuery query;
    QString file_name_base = "rzhd.db";
    StationMap map;
    int countGraphs = 0;
    Qt::GlobalColor currentColor = Qt::darkGray;
    int countRoute = 0;
    double max_x = 0;
    double min_x = 0;
    double max_y = 0;
    double min_y = 0;
};

#endif // MAINWINDOW_H

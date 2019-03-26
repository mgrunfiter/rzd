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
    Ui::MainWindow *ui;
    bool MessBox(QString message);
    QSqlDatabase dbs;
    QSqlQuery query;
//    QString file_name_base = "rzhd.db";
//    QString file_name_base = "D:/_git/cpp/cjunior-2019/final_task/db/rzhd.db";
    QString file_name_base = "/home/csv/study/github/rzd/db/rzhd.db";
//    QString file_name_base = "*//home/family/cpp/cjunior-2019/final_task/db/rzhd.db";
//    QString file_name_base = "D:/_git/cpp/rzd/db/rzhd.db";
    StationMap map;
    double max_x = 0;
    double min_x = 0;
    double max_y = 0;
    double min_y = 0;
};

#endif // MAINWINDOW_H

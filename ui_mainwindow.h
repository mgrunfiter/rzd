/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCustomPlot *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbFileDase;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leBaseFile;
    QToolButton *tbBaseFile;
    QLabel *lbFrom;
    QComboBox *cbFrom;
    QLabel *lbTo;
    QComboBox *cbTo;
    QPushButton *pbFindRoute;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(680, 340);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(true);

        horizontalLayout_3->addWidget(widget);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbFileDase = new QLabel(centralWidget);
        lbFileDase->setObjectName(QString::fromUtf8("lbFileDase"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbFileDase->sizePolicy().hasHeightForWidth());
        lbFileDase->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lbFileDase);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leBaseFile = new QLineEdit(centralWidget);
        leBaseFile->setObjectName(QString::fromUtf8("leBaseFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leBaseFile->sizePolicy().hasHeightForWidth());
        leBaseFile->setSizePolicy(sizePolicy1);
        leBaseFile->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(leBaseFile);

        tbBaseFile = new QToolButton(centralWidget);
        tbBaseFile->setObjectName(QString::fromUtf8("tbBaseFile"));

        horizontalLayout->addWidget(tbBaseFile);

        lbFrom = new QLabel(centralWidget);
        lbFrom->setObjectName(QString::fromUtf8("lbFrom"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbFrom->sizePolicy().hasHeightForWidth());
        lbFrom->setSizePolicy(sizePolicy2);
        lbFrom->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(lbFrom);

        cbFrom = new QComboBox(centralWidget);
        cbFrom->setObjectName(QString::fromUtf8("cbFrom"));
        sizePolicy2.setHeightForWidth(cbFrom->sizePolicy().hasHeightForWidth());
        cbFrom->setSizePolicy(sizePolicy2);
        cbFrom->setInputMethodHints(Qt::ImhNone);
        cbFrom->setEditable(true);

        horizontalLayout->addWidget(cbFrom);

        lbTo = new QLabel(centralWidget);
        lbTo->setObjectName(QString::fromUtf8("lbTo"));
        sizePolicy2.setHeightForWidth(lbTo->sizePolicy().hasHeightForWidth());
        lbTo->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lbTo);

        cbTo = new QComboBox(centralWidget);
        cbTo->setObjectName(QString::fromUtf8("cbTo"));
        sizePolicy2.setHeightForWidth(cbTo->sizePolicy().hasHeightForWidth());
        cbTo->setSizePolicy(sizePolicy2);
        cbTo->setEditable(true);

        horizontalLayout->addWidget(cbTo);

        pbFindRoute = new QPushButton(centralWidget);
        pbFindRoute->setObjectName(QString::fromUtf8("pbFindRoute"));

        horizontalLayout->addWidget(pbFindRoute);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lbFileDase->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\221\320\224:", nullptr));
        leBaseFile->setPlaceholderText(QApplication::translate("MainWindow", "path to rzhd.db file", nullptr));
        tbBaseFile->setText(QApplication::translate("MainWindow", "...", nullptr));
        lbFrom->setText(QApplication::translate("MainWindow", "\320\230\320\267:    ", nullptr));
        lbTo->setText(QApplication::translate("MainWindow", "\320\222:  ", nullptr));
        pbFindRoute->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

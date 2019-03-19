/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(680, 340);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(true);

        horizontalLayout_3->addWidget(widget);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbFileDase = new QLabel(centralWidget);
        lbFileDase->setObjectName(QStringLiteral("lbFileDase"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbFileDase->sizePolicy().hasHeightForWidth());
        lbFileDase->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lbFileDase);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leBaseFile = new QLineEdit(centralWidget);
        leBaseFile->setObjectName(QStringLiteral("leBaseFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leBaseFile->sizePolicy().hasHeightForWidth());
        leBaseFile->setSizePolicy(sizePolicy1);
        leBaseFile->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(leBaseFile);

        tbBaseFile = new QToolButton(centralWidget);
        tbBaseFile->setObjectName(QStringLiteral("tbBaseFile"));

        horizontalLayout->addWidget(tbBaseFile);

        lbFrom = new QLabel(centralWidget);
        lbFrom->setObjectName(QStringLiteral("lbFrom"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbFrom->sizePolicy().hasHeightForWidth());
        lbFrom->setSizePolicy(sizePolicy2);
        lbFrom->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(lbFrom);

        cbFrom = new QComboBox(centralWidget);
        cbFrom->setObjectName(QStringLiteral("cbFrom"));
        sizePolicy2.setHeightForWidth(cbFrom->sizePolicy().hasHeightForWidth());
        cbFrom->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(cbFrom);

        lbTo = new QLabel(centralWidget);
        lbTo->setObjectName(QStringLiteral("lbTo"));
        sizePolicy2.setHeightForWidth(lbTo->sizePolicy().hasHeightForWidth());
        lbTo->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lbTo);

        cbTo = new QComboBox(centralWidget);
        cbTo->setObjectName(QStringLiteral("cbTo"));
        sizePolicy2.setHeightForWidth(cbTo->sizePolicy().hasHeightForWidth());
        cbTo->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(cbTo);

        pbFindRoute = new QPushButton(centralWidget);
        pbFindRoute->setObjectName(QStringLiteral("pbFindRoute"));

        horizontalLayout->addWidget(pbFindRoute);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lbFileDase->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\221\320\224:", Q_NULLPTR));
        leBaseFile->setPlaceholderText(QApplication::translate("MainWindow", "path to rzhd.db file", Q_NULLPTR));
        tbBaseFile->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        lbFrom->setText(QApplication::translate("MainWindow", "\320\230\320\267:    ", Q_NULLPTR));
        lbTo->setText(QApplication::translate("MainWindow", "\320\222:  ", Q_NULLPTR));
        pbFindRoute->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

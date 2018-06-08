/********************************************************************************
** Form generated from reading UI file 'uiGraphDigitizer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIGRAPHDIGITIZER_H
#define UI_UIGRAPHDIGITIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ImageLabel.h"

QT_BEGIN_NAMESPACE

class Ui_GraphDigitizerClass
{
public:
    QAction *actionOpen;
    QAction *actionSaveAs;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionAdd_Dataset;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionNormal_Size;
    QAction *action_Fit_to_Window;
    QAction *action_About;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *axisVL;
    QCheckBox *displayAxisChk;
    QHBoxLayout *xAxisHL;
    QLabel *x1AxisLabel;
    QLineEdit *x1AxisField;
    QLabel *x2AxisLabel;
    QLineEdit *x2AxisField;
    QHBoxLayout *yAxisHL;
    QLabel *y1AxisLabel;
    QLineEdit *y1AxisField;
    QLabel *y2AxisLabel;
    QLineEdit *y2AxisField;
    QPushButton *setTransformBtn;
    QPushButton *clearAxisBtn;
    QTableWidget *tableWidget_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    ImageLabel *imageLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphDigitizerClass)
    {
        if (GraphDigitizerClass->objectName().isEmpty())
            GraphDigitizerClass->setObjectName(QStringLiteral("GraphDigitizerClass"));
        GraphDigitizerClass->resize(950, 708);
        GraphDigitizerClass->setMouseTracking(true);
        actionOpen = new QAction(GraphDigitizerClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSaveAs = new QAction(GraphDigitizerClass);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSaveAs->setEnabled(false);
        actionPrint = new QAction(GraphDigitizerClass);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionPrint->setEnabled(false);
        actionExit = new QAction(GraphDigitizerClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionCopy = new QAction(GraphDigitizerClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCopy->setEnabled(false);
        actionPaste = new QAction(GraphDigitizerClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionAdd_Dataset = new QAction(GraphDigitizerClass);
        actionAdd_Dataset->setObjectName(QStringLiteral("actionAdd_Dataset"));
        actionAdd_Dataset->setCheckable(true);
        actionZoom_In = new QAction(GraphDigitizerClass);
        actionZoom_In->setObjectName(QStringLiteral("actionZoom_In"));
        actionZoom_In->setEnabled(false);
        actionZoom_Out = new QAction(GraphDigitizerClass);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        actionZoom_Out->setEnabled(false);
        actionNormal_Size = new QAction(GraphDigitizerClass);
        actionNormal_Size->setObjectName(QStringLiteral("actionNormal_Size"));
        actionNormal_Size->setEnabled(false);
        action_Fit_to_Window = new QAction(GraphDigitizerClass);
        action_Fit_to_Window->setObjectName(QStringLiteral("action_Fit_to_Window"));
        action_Fit_to_Window->setCheckable(true);
        action_Fit_to_Window->setEnabled(false);
        action_About = new QAction(GraphDigitizerClass);
        action_About->setObjectName(QStringLiteral("action_About"));
        actionAbout_Qt = new QAction(GraphDigitizerClass);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralWidget = new QWidget(GraphDigitizerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        axisVL = new QVBoxLayout();
        axisVL->setSpacing(6);
        axisVL->setObjectName(QStringLiteral("axisVL"));
        axisVL->setSizeConstraint(QLayout::SetDefaultConstraint);
        displayAxisChk = new QCheckBox(centralWidget);
        displayAxisChk->setObjectName(QStringLiteral("displayAxisChk"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayAxisChk->sizePolicy().hasHeightForWidth());
        displayAxisChk->setSizePolicy(sizePolicy);
        displayAxisChk->setMaximumSize(QSize(200, 20));

        axisVL->addWidget(displayAxisChk);

        xAxisHL = new QHBoxLayout();
        xAxisHL->setSpacing(6);
        xAxisHL->setObjectName(QStringLiteral("xAxisHL"));
        x1AxisLabel = new QLabel(centralWidget);
        x1AxisLabel->setObjectName(QStringLiteral("x1AxisLabel"));
        x1AxisLabel->setMaximumSize(QSize(200, 16777215));

        xAxisHL->addWidget(x1AxisLabel);

        x1AxisField = new QLineEdit(centralWidget);
        x1AxisField->setObjectName(QStringLiteral("x1AxisField"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(x1AxisField->sizePolicy().hasHeightForWidth());
        x1AxisField->setSizePolicy(sizePolicy1);
        x1AxisField->setMaximumSize(QSize(200, 20));

        xAxisHL->addWidget(x1AxisField);

        x2AxisLabel = new QLabel(centralWidget);
        x2AxisLabel->setObjectName(QStringLiteral("x2AxisLabel"));
        sizePolicy.setHeightForWidth(x2AxisLabel->sizePolicy().hasHeightForWidth());
        x2AxisLabel->setSizePolicy(sizePolicy);
        x2AxisLabel->setMaximumSize(QSize(200, 130));

        xAxisHL->addWidget(x2AxisLabel);

        x2AxisField = new QLineEdit(centralWidget);
        x2AxisField->setObjectName(QStringLiteral("x2AxisField"));
        sizePolicy1.setHeightForWidth(x2AxisField->sizePolicy().hasHeightForWidth());
        x2AxisField->setSizePolicy(sizePolicy1);
        x2AxisField->setMaximumSize(QSize(200, 20));

        xAxisHL->addWidget(x2AxisField);


        axisVL->addLayout(xAxisHL);

        yAxisHL = new QHBoxLayout();
        yAxisHL->setSpacing(6);
        yAxisHL->setObjectName(QStringLiteral("yAxisHL"));
        y1AxisLabel = new QLabel(centralWidget);
        y1AxisLabel->setObjectName(QStringLiteral("y1AxisLabel"));
        y1AxisLabel->setMaximumSize(QSize(200, 16777215));

        yAxisHL->addWidget(y1AxisLabel);

        y1AxisField = new QLineEdit(centralWidget);
        y1AxisField->setObjectName(QStringLiteral("y1AxisField"));
        sizePolicy1.setHeightForWidth(y1AxisField->sizePolicy().hasHeightForWidth());
        y1AxisField->setSizePolicy(sizePolicy1);
        y1AxisField->setMaximumSize(QSize(200, 20));

        yAxisHL->addWidget(y1AxisField);

        y2AxisLabel = new QLabel(centralWidget);
        y2AxisLabel->setObjectName(QStringLiteral("y2AxisLabel"));
        sizePolicy.setHeightForWidth(y2AxisLabel->sizePolicy().hasHeightForWidth());
        y2AxisLabel->setSizePolicy(sizePolicy);
        y2AxisLabel->setMaximumSize(QSize(200, 130));

        yAxisHL->addWidget(y2AxisLabel);

        y2AxisField = new QLineEdit(centralWidget);
        y2AxisField->setObjectName(QStringLiteral("y2AxisField"));
        sizePolicy1.setHeightForWidth(y2AxisField->sizePolicy().hasHeightForWidth());
        y2AxisField->setSizePolicy(sizePolicy1);
        y2AxisField->setMaximumSize(QSize(200, 20));

        yAxisHL->addWidget(y2AxisField);


        axisVL->addLayout(yAxisHL);

        setTransformBtn = new QPushButton(centralWidget);
        setTransformBtn->setObjectName(QStringLiteral("setTransformBtn"));
        sizePolicy.setHeightForWidth(setTransformBtn->sizePolicy().hasHeightForWidth());
        setTransformBtn->setSizePolicy(sizePolicy);
        setTransformBtn->setMaximumSize(QSize(200, 20));

        axisVL->addWidget(setTransformBtn);

        clearAxisBtn = new QPushButton(centralWidget);
        clearAxisBtn->setObjectName(QStringLiteral("clearAxisBtn"));
        sizePolicy.setHeightForWidth(clearAxisBtn->sizePolicy().hasHeightForWidth());
        clearAxisBtn->setSizePolicy(sizePolicy);
        clearAxisBtn->setMaximumSize(QSize(200, 20));

        axisVL->addWidget(clearAxisBtn);


        gridLayout->addLayout(axisVL, 0, 1, 1, 1);

        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setEnabled(true);
        tableWidget_2->setMinimumSize(QSize(0, 450));
        tableWidget_2->setMaximumSize(QSize(202, 500));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setGridStyle(Qt::SolidLine);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(0);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableWidget_2, 1, 1, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 722, 635));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        imageLabel = new ImageLabel(scrollAreaWidgetContents_2);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy2);
        imageLabel->setMouseTracking(true);
        imageLabel->setScaledContents(true);

        verticalLayout->addWidget(imageLabel);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 0, 2, 1);

        GraphDigitizerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphDigitizerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        GraphDigitizerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraphDigitizerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GraphDigitizerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GraphDigitizerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GraphDigitizerClass->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        x1AxisLabel->setBuddy(x1AxisField);
        x2AxisLabel->setBuddy(x2AxisField);
        y1AxisLabel->setBuddy(y1AxisField);
        y2AxisLabel->setBuddy(y2AxisField);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(displayAxisChk, x1AxisField);
        QWidget::setTabOrder(x1AxisField, x2AxisField);
        QWidget::setTabOrder(x2AxisField, y1AxisField);
        QWidget::setTabOrder(y1AxisField, y2AxisField);
        QWidget::setTabOrder(y2AxisField, setTransformBtn);
        QWidget::setTabOrder(setTransformBtn, clearAxisBtn);
        QWidget::setTabOrder(clearAxisBtn, tableWidget_2);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionAdd_Dataset);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);
        menuView->addAction(actionNormal_Size);
        menuView->addSeparator();
        menuView->addAction(action_Fit_to_Window);
        menu_Help->addAction(action_About);

        retranslateUi(GraphDigitizerClass);

        QMetaObject::connectSlotsByName(GraphDigitizerClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphDigitizerClass)
    {
        GraphDigitizerClass->setWindowTitle(QApplication::translate("GraphDigitizerClass", "GraphDigitizer", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("GraphDigitizerClass", "&Open...", Q_NULLPTR));
        actionSaveAs->setText(QApplication::translate("GraphDigitizerClass", "&SaveAs...", Q_NULLPTR));
        actionPrint->setText(QApplication::translate("GraphDigitizerClass", "&Print...", Q_NULLPTR));
        actionExit->setText(QApplication::translate("GraphDigitizerClass", "E&xit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("GraphDigitizerClass", "&Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("GraphDigitizerClass", "&Paste", Q_NULLPTR));
        actionAdd_Dataset->setText(QApplication::translate("GraphDigitizerClass", "&Add Dataset", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionAdd_Dataset->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionZoom_In->setText(QApplication::translate("GraphDigitizerClass", "Zoom &In (25%)", Q_NULLPTR));
        actionZoom_Out->setText(QApplication::translate("GraphDigitizerClass", "Zoom &Out (25%)", Q_NULLPTR));
        actionNormal_Size->setText(QApplication::translate("GraphDigitizerClass", "&Normal Size", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNormal_Size->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Fit_to_Window->setText(QApplication::translate("GraphDigitizerClass", "&Fit to Window", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Fit_to_Window->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_About->setText(QApplication::translate("GraphDigitizerClass", "&About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("GraphDigitizerClass", "About &Qt", Q_NULLPTR));
        displayAxisChk->setText(QApplication::translate("GraphDigitizerClass", "Display Axis", Q_NULLPTR));
        x1AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "X1", Q_NULLPTR));
        x1AxisField->setText(QApplication::translate("GraphDigitizerClass", "0", Q_NULLPTR));
        x2AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "X2", Q_NULLPTR));
        x2AxisField->setText(QApplication::translate("GraphDigitizerClass", "1", Q_NULLPTR));
        y1AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "Y1", Q_NULLPTR));
        y1AxisField->setText(QApplication::translate("GraphDigitizerClass", "0", Q_NULLPTR));
        y2AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "Y2", Q_NULLPTR));
        y2AxisField->setText(QApplication::translate("GraphDigitizerClass", "1", Q_NULLPTR));
        setTransformBtn->setText(QApplication::translate("GraphDigitizerClass", "Set Transform", Q_NULLPTR));
        clearAxisBtn->setText(QApplication::translate("GraphDigitizerClass", "Clear Axis", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GraphDigitizerClass", "X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GraphDigitizerClass", "Y", Q_NULLPTR));
        imageLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("GraphDigitizerClass", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("GraphDigitizerClass", "&Edit", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("GraphDigitizerClass", "&View", Q_NULLPTR));
        menu_Help->setTitle(QApplication::translate("GraphDigitizerClass", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GraphDigitizerClass: public Ui_GraphDigitizerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIGRAPHDIGITIZER_H

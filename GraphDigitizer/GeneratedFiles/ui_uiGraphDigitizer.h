/********************************************************************************
** Form generated from reading UI file 'uiGraphDigitizer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIGRAPHDIGITIZER_H
#define UI_UIGRAPHDIGITIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ImageLabel.h"
#include "QuantizedColorLabel.h"

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
    QAction *actionSet_AOI;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *nrColorsSB;
    QPushButton *quantizedImageBtn;
    QuantizedColorLabel *quantizedColorLabel;
    QTableWidget *tableWidget_2;
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
    ImageLabel *resultLabel;
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
        GraphDigitizerClass->resize(1043, 684);
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
        actionSet_AOI = new QAction(GraphDigitizerClass);
        actionSet_AOI->setObjectName(QStringLiteral("actionSet_AOI"));
        centralWidget = new QWidget(GraphDigitizerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nrColorsSB = new QSpinBox(centralWidget);
        nrColorsSB->setObjectName(QStringLiteral("nrColorsSB"));
        nrColorsSB->setAlignment(Qt::AlignCenter);
        nrColorsSB->setMinimum(2);
        nrColorsSB->setMaximum(64);

        horizontalLayout->addWidget(nrColorsSB);


        verticalLayout_2->addLayout(horizontalLayout);

        quantizedImageBtn = new QPushButton(centralWidget);
        quantizedImageBtn->setObjectName(QStringLiteral("quantizedImageBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quantizedImageBtn->sizePolicy().hasHeightForWidth());
        quantizedImageBtn->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(quantizedImageBtn);

        quantizedColorLabel = new QuantizedColorLabel(centralWidget);
        quantizedColorLabel->setObjectName(QStringLiteral("quantizedColorLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(quantizedColorLabel->sizePolicy().hasHeightForWidth());
        quantizedColorLabel->setSizePolicy(sizePolicy1);
        quantizedColorLabel->setMinimumSize(QSize(100, 100));
        quantizedColorLabel->setMaximumSize(QSize(100, 100));
        quantizedColorLabel->setMouseTracking(true);
        quantizedColorLabel->setAutoFillBackground(true);
        quantizedColorLabel->setScaledContents(true);
        quantizedColorLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(quantizedColorLabel);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

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

        gridLayout->addWidget(tableWidget_2, 7, 2, 1, 1);

        axisVL = new QVBoxLayout();
        axisVL->setSpacing(6);
        axisVL->setObjectName(QStringLiteral("axisVL"));
        axisVL->setSizeConstraint(QLayout::SetDefaultConstraint);
        displayAxisChk = new QCheckBox(centralWidget);
        displayAxisChk->setObjectName(QStringLiteral("displayAxisChk"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(displayAxisChk->sizePolicy().hasHeightForWidth());
        displayAxisChk->setSizePolicy(sizePolicy2);
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
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(x1AxisField->sizePolicy().hasHeightForWidth());
        x1AxisField->setSizePolicy(sizePolicy3);
        x1AxisField->setMaximumSize(QSize(200, 20));
        x1AxisField->setAlignment(Qt::AlignCenter);

        xAxisHL->addWidget(x1AxisField);

        x2AxisLabel = new QLabel(centralWidget);
        x2AxisLabel->setObjectName(QStringLiteral("x2AxisLabel"));
        sizePolicy2.setHeightForWidth(x2AxisLabel->sizePolicy().hasHeightForWidth());
        x2AxisLabel->setSizePolicy(sizePolicy2);
        x2AxisLabel->setMaximumSize(QSize(200, 130));

        xAxisHL->addWidget(x2AxisLabel);

        x2AxisField = new QLineEdit(centralWidget);
        x2AxisField->setObjectName(QStringLiteral("x2AxisField"));
        sizePolicy3.setHeightForWidth(x2AxisField->sizePolicy().hasHeightForWidth());
        x2AxisField->setSizePolicy(sizePolicy3);
        x2AxisField->setMaximumSize(QSize(200, 20));
        x2AxisField->setAlignment(Qt::AlignCenter);

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
        sizePolicy3.setHeightForWidth(y1AxisField->sizePolicy().hasHeightForWidth());
        y1AxisField->setSizePolicy(sizePolicy3);
        y1AxisField->setMaximumSize(QSize(200, 20));
        y1AxisField->setAlignment(Qt::AlignCenter);

        yAxisHL->addWidget(y1AxisField);

        y2AxisLabel = new QLabel(centralWidget);
        y2AxisLabel->setObjectName(QStringLiteral("y2AxisLabel"));
        sizePolicy2.setHeightForWidth(y2AxisLabel->sizePolicy().hasHeightForWidth());
        y2AxisLabel->setSizePolicy(sizePolicy2);
        y2AxisLabel->setMaximumSize(QSize(200, 130));

        yAxisHL->addWidget(y2AxisLabel);

        y2AxisField = new QLineEdit(centralWidget);
        y2AxisField->setObjectName(QStringLiteral("y2AxisField"));
        sizePolicy3.setHeightForWidth(y2AxisField->sizePolicy().hasHeightForWidth());
        y2AxisField->setSizePolicy(sizePolicy3);
        y2AxisField->setMaximumSize(QSize(200, 20));
        y2AxisField->setAlignment(Qt::AlignCenter);

        yAxisHL->addWidget(y2AxisField);


        axisVL->addLayout(yAxisHL);

        setTransformBtn = new QPushButton(centralWidget);
        setTransformBtn->setObjectName(QStringLiteral("setTransformBtn"));
        sizePolicy2.setHeightForWidth(setTransformBtn->sizePolicy().hasHeightForWidth());
        setTransformBtn->setSizePolicy(sizePolicy2);
        setTransformBtn->setMaximumSize(QSize(200, 20));

        axisVL->addWidget(setTransformBtn);

        clearAxisBtn = new QPushButton(centralWidget);
        clearAxisBtn->setObjectName(QStringLiteral("clearAxisBtn"));
        sizePolicy2.setHeightForWidth(clearAxisBtn->sizePolicy().hasHeightForWidth());
        clearAxisBtn->setSizePolicy(sizePolicy2);
        clearAxisBtn->setMaximumSize(QSize(200, 20));

        axisVL->addWidget(clearAxisBtn);


        gridLayout->addLayout(axisVL, 2, 2, 1, 1);

        resultLabel = new ImageLabel(centralWidget);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(resultLabel->sizePolicy().hasHeightForWidth());
        resultLabel->setSizePolicy(sizePolicy4);
        resultLabel->setMinimumSize(QSize(100, 100));
        resultLabel->setMaximumSize(QSize(100, 100));
        resultLabel->setAutoFillBackground(true);
        resultLabel->setScaledContents(false);
        resultLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(resultLabel, 7, 0, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 707, 611));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        imageLabel = new ImageLabel(scrollAreaWidgetContents_2);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy5);
        imageLabel->setMouseTracking(true);
        imageLabel->setScaledContents(true);

        verticalLayout->addWidget(imageLabel);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 2, 1, 6, 1);

        GraphDigitizerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphDigitizerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1043, 21));
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
        label->setBuddy(nrColorsSB);
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
        menuEdit->addSeparator();
        menuEdit->addAction(actionAdd_Dataset);
        menuEdit->addAction(actionSet_AOI);
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
        GraphDigitizerClass->setWindowTitle(QApplication::translate("GraphDigitizerClass", "GraphDigitizer", nullptr));
        actionOpen->setText(QApplication::translate("GraphDigitizerClass", "&Open...", nullptr));
        actionSaveAs->setText(QApplication::translate("GraphDigitizerClass", "&SaveAs...", nullptr));
        actionPrint->setText(QApplication::translate("GraphDigitizerClass", "&Print...", nullptr));
        actionExit->setText(QApplication::translate("GraphDigitizerClass", "E&xit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("GraphDigitizerClass", "&Copy", nullptr));
        actionPaste->setText(QApplication::translate("GraphDigitizerClass", "&Paste", nullptr));
        actionAdd_Dataset->setText(QApplication::translate("GraphDigitizerClass", "&Add Dataset", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAdd_Dataset->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_In->setText(QApplication::translate("GraphDigitizerClass", "Zoom &In (25%)", nullptr));
        actionZoom_Out->setText(QApplication::translate("GraphDigitizerClass", "Zoom &Out (25%)", nullptr));
        actionNormal_Size->setText(QApplication::translate("GraphDigitizerClass", "&Normal Size", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNormal_Size->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Fit_to_Window->setText(QApplication::translate("GraphDigitizerClass", "&Fit to Window", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Fit_to_Window->setShortcut(QApplication::translate("GraphDigitizerClass", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        action_About->setText(QApplication::translate("GraphDigitizerClass", "&About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("GraphDigitizerClass", "About &Qt", nullptr));
        actionSet_AOI->setText(QApplication::translate("GraphDigitizerClass", "Set AOI", nullptr));
        label->setText(QApplication::translate("GraphDigitizerClass", "Colors", nullptr));
        quantizedImageBtn->setText(QApplication::translate("GraphDigitizerClass", "Quantize Image", nullptr));
        quantizedColorLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GraphDigitizerClass", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GraphDigitizerClass", "Y", nullptr));
        displayAxisChk->setText(QApplication::translate("GraphDigitizerClass", "Display Axis", nullptr));
        x1AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "X1", nullptr));
        x1AxisField->setText(QApplication::translate("GraphDigitizerClass", "0", nullptr));
        x2AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "X2", nullptr));
        x2AxisField->setText(QApplication::translate("GraphDigitizerClass", "1", nullptr));
        y1AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "Y1", nullptr));
        y1AxisField->setText(QApplication::translate("GraphDigitizerClass", "0", nullptr));
        y2AxisLabel->setText(QApplication::translate("GraphDigitizerClass", "Y2", nullptr));
        y2AxisField->setText(QApplication::translate("GraphDigitizerClass", "1", nullptr));
        setTransformBtn->setText(QApplication::translate("GraphDigitizerClass", "Set Transform", nullptr));
        clearAxisBtn->setText(QApplication::translate("GraphDigitizerClass", "Clear Axis", nullptr));
        resultLabel->setText(QApplication::translate("GraphDigitizerClass", "Preview", nullptr));
        imageLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("GraphDigitizerClass", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("GraphDigitizerClass", "&Edit", nullptr));
        menuView->setTitle(QApplication::translate("GraphDigitizerClass", "&View", nullptr));
        menu_Help->setTitle(QApplication::translate("GraphDigitizerClass", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphDigitizerClass: public Ui_GraphDigitizerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIGRAPHDIGITIZER_H

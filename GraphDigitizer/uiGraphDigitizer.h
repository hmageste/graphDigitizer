#pragma once

// In case we want to be old-fashioned
//#ifndef uiGraphDigitizer_H
//#define uiGraphDigitizer_H

#include <QtWidgets/QMainWindow>
#ifndef QT_NO_PRINTER
#include <QtPrintSupport/QPrinter>
#endif

#include "ui_uiGraphDigitizer.h"

class QImage;
class QScrollBar;

class uiGraphDigitizer : public QMainWindow
{
    Q_OBJECT

public:
    uiGraphDigitizer(QWidget *parent = Q_NULLPTR);
    bool loadFile (const QString &);

private slots:
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_actionPrint_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionNormal_Size_triggered();
    void on_action_Fit_to_Window_triggered();
    void on_action_About_triggered();

    void on_actionAdd_Dataset_triggered(bool checked);
    void on_setTransformBtn_clicked();
    void on_clearAxisBtn_clicked();
    void on_displayAxisChk_stateChanged(int);

    void setStatusBarText(const QString&);

private:
    void configureActions ();
    void connectSignalsSlots();
    void updateActions();
    bool saveFile(const QString& fileName);
    void setImage(const QImage& newImage);
    void scaleImage(float factor);
    void adjustScrollBar(QScrollBar* scrollBar, float factor);

#ifndef QT_NO_PRINTER
    QPrinter printer;
#endif

private:
    Ui::GraphDigitizerClass ui;
    GraphDigitizer* graphDigitizer_;
};

//#endif

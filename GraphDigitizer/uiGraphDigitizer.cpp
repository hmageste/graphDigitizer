#include "uiGraphDigitizer.h"

#include "ImageLabel.h"
#include "GraphDigitizer.h"

#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#endif

uiGraphDigitizer::uiGraphDigitizer (QWidget *parent)
    : QMainWindow(parent)
    , graphDigitizer_(0)
{
    ui.setupUi(this);
    graphDigitizer_ = &ui.imageLabel->getModel(); //Provides a shortcut for the model

    ui.scrollArea->setBackgroundRole(QPalette::Dark);
    ui.scrollArea->setVisible(true);

    ui.displayAxisChk->setChecked(ui.imageLabel->displayAxis());

    configureActions ();

    resize (QGuiApplication::primaryScreen ()->availableSize () * 3 / 5);

    connectSignalsSlots();
}

void uiGraphDigitizer::connectSignalsSlots()
{
    connect(ui.imageLabel, SIGNAL(statusEvent(QString)), this, SLOT(setStatusBarText(QString)));
}

bool uiGraphDigitizer::loadFile (const QString &fileName)
{
    QImageReader reader (fileName);
    reader.setAutoTransform (true);
    const QImage newImage = reader.read ();
    if (newImage.isNull ()) {
        QMessageBox::information (this, QGuiApplication::applicationDisplayName (),
                                  tr ("Cannot load %1: %2")
                                  .arg (QDir::toNativeSeparators (fileName), reader.errorString ()));
        return false;
    }

    setImage (newImage);

    setWindowFilePath (fileName);

    const QImage& image = ui.imageLabel->image();
    const QString message = tr ("Opened \"%1\", %2x%3, Depth: %4")
        .arg (QDir::toNativeSeparators (fileName)).arg (image.width ()).arg (image.height ()).arg (image.depth ());
    statusBar ()->showMessage (message);

    return true;
}

void uiGraphDigitizer::setImage (const QImage &newImage)
{
    ui.imageLabel->setImage(newImage);
    ui.actionPrint->setEnabled (true);
    ui.action_Fit_to_Window->setEnabled (true);
    on_action_Fit_to_Window_triggered();
}


bool uiGraphDigitizer::saveFile (const QString &fileName)
{
    QImageWriter writer (fileName);

    if (!writer.write (ui.imageLabel->image())) {
        QMessageBox::information (this, QGuiApplication::applicationDisplayName (),
                                  tr ("Cannot write %1: %2")
                                  .arg (QDir::toNativeSeparators (fileName)), writer.errorString ());
        return false;
    }
    const QString message = tr ("Wrote \"%1\"").arg (QDir::toNativeSeparators (fileName));
    statusBar ()->showMessage (message);
    return true;
}


static void initializeImageFileDialog (QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations (QStandardPaths::PicturesLocation);
        dialog.setDirectory (picturesLocations.isEmpty () ? QDir::currentPath () : picturesLocations.last ());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes () : QImageWriter::supportedMimeTypes ();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append (mimeTypeName);
    mimeTypeFilters.sort ();
    dialog.setMimeTypeFilters (mimeTypeFilters);
    dialog.selectMimeTypeFilter ("image/png");

    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix ("jpg");
}

void uiGraphDigitizer::on_actionOpen_triggered()
{
    QFileDialog dialog (this, tr ("Open File"));
    initializeImageFileDialog (dialog, QFileDialog::AcceptOpen);

    while (dialog.exec () == QDialog::Accepted && !loadFile (dialog.selectedFiles ().first ())) {}
}

void uiGraphDigitizer::on_actionSaveAs_triggered()
{
    QFileDialog dialog (this, tr ("Save File As"));
    initializeImageFileDialog (dialog, QFileDialog::AcceptSave);

    while (dialog.exec () == QDialog::Accepted && !saveFile (dialog.selectedFiles ().first ())) {}
}

void uiGraphDigitizer::on_actionPrint_triggered()
{
    Q_ASSERT (ui.imageLabel->pixmap ());
#if QT_CONFIG(printdialog)
    QPrintDialog dialog (&printer, this);
    if (dialog.exec ()) {
        QPainter painter (&printer);
        QRect rect = painter.viewport ();
        QSize size = ui.imageLabel->pixmap ()->size ();
        size.scale (rect.size (), Qt::KeepAspectRatio);
        painter.setViewport (rect.x (), rect.y (), size.width (), size.height ());
        painter.setWindow (ui.imageLabel->pixmap ()->rect ());
        painter.drawPixmap (0, 0, *ui.imageLabel->pixmap ());
    }
#endif
}

void uiGraphDigitizer::on_actionCopy_triggered()
{
#ifndef QT_NO_CLIPBOARD
    QGuiApplication::clipboard ()->setImage (ui.imageLabel->image());
#endif // !QT_NO_CLIPBOARD
}

#ifndef QT_NO_CLIPBOARD
static QImage clipboardImage ()
{
    if (const QMimeData *mimeData = QGuiApplication::clipboard ()->mimeData ()) {
        if (mimeData->hasImage ()) {
            const QImage image = qvariant_cast<QImage>(mimeData->imageData ());
            if (!image.isNull ())
                return image;
        }
    }
    return QImage ();
}
#endif // !QT_NO_CLIPBOARD

void uiGraphDigitizer::on_actionPaste_triggered()
{
#ifndef QT_NO_CLIPBOARD
    const QImage newImage = clipboardImage ();
    if (newImage.isNull ()) {
        statusBar ()->showMessage (tr ("No image in clipboard"));
    }
    else {
        setImage (newImage);
        setWindowFilePath (QString ());
        const QString message = tr ("Obtained image from clipboard, %1x%2, Depth: %3")
            .arg (newImage.width ()).arg (newImage.height ()).arg (newImage.depth ());
        statusBar ()->showMessage (message);
    }
#endif // !QT_NO_CLIPBOARD
}

void uiGraphDigitizer::on_actionZoom_In_triggered()
{
    scaleImage (1.25f);
}

void uiGraphDigitizer::on_actionZoom_Out_triggered()
{
    scaleImage (0.8f);
}

void uiGraphDigitizer::on_actionNormal_Size_triggered()
{
    ui.imageLabel->adjustSize ();
    ui.imageLabel->setScaleFactor(1.0f);
}

void uiGraphDigitizer::on_action_Fit_to_Window_triggered()
{
    bool fitToWindow = ui.action_Fit_to_Window->isChecked ();
    ui.scrollArea->setWidgetResizable (fitToWindow);
    if (!fitToWindow)
        on_actionNormal_Size_triggered ();
    updateActions ();
}

void uiGraphDigitizer::on_action_About_triggered()
{
    QMessageBox::about (this, tr ("About Graph Digitizer"),
                        tr ("<p>The <b>Graph Digitizer</b> is a software to digitilize graph "
                            "points giving the user the ability to create their own graphs. "
                            "<p>Author: Henrique Mageste</p>"));
}


void uiGraphDigitizer::on_actionAdd_Dataset_triggered(bool checked)
{
    ui.imageLabel->pickMode(checked);
}


void uiGraphDigitizer::on_setTransformBtn_clicked()
{
    const float worldX1 = ui.x1AxisField->text().toFloat();
    const float worldX2 = ui.x2AxisField->text().toFloat();
    const float worldY1 = ui.y1AxisField->text().toFloat();
    const float worldY2 = ui.y2AxisField->text().toFloat();

    graphDigitizer_->setX1Axis(worldX1);
    graphDigitizer_->setX2Axis(worldX2);
    graphDigitizer_->setY1Axis(worldY1);
    graphDigitizer_->setY2Axis(worldY2);

    graphDigitizer_->setPxAxisCoords(ui.imageLabel->getPxAxisPoints());
    graphDigitizer_->setTransform();

    ui.setTransformBtn->setEnabled(false);
}


void uiGraphDigitizer::on_clearAxisBtn_clicked()
{
    ui.setTransformBtn->setEnabled(true);
    ui.imageLabel->clearAxisPoints();
}


void uiGraphDigitizer::on_displayAxisChk_stateChanged(int state)
{
    ui.imageLabel->displayAxis(static_cast<bool>(state));
}


void uiGraphDigitizer::setStatusBarText(const QString& msg)
{
    ui.statusBar->showMessage(msg);
}


void uiGraphDigitizer::configureActions ()
{
    ui.actionOpen->setShortcut (QKeySequence::Open);
    ui.actionPrint->setShortcut (QKeySequence::Print);
    ui.actionCopy->setShortcut (QKeySequence::Copy);
    ui.actionPaste->setShortcut (QKeySequence::Paste);
    ui.actionZoom_In->setShortcut (QKeySequence::ZoomIn);
    ui.actionZoom_Out->setShortcut (QKeySequence::ZoomOut);
    ui.menu_Help->addAction (tr ("About &Qt"), &QApplication::aboutQt);
}


void uiGraphDigitizer::updateActions ()
{
    const QImage& image = ui.imageLabel->image();
    ui.actionSaveAs->setEnabled (!image.isNull ());
    ui.actionCopy->setEnabled (!image.isNull ());
    ui.actionZoom_In->setEnabled (!ui.action_Fit_to_Window->isChecked ());
    ui.actionZoom_Out->setEnabled (!ui.action_Fit_to_Window->isChecked ());
    ui.actionNormal_Size->setEnabled (!ui.action_Fit_to_Window->isChecked ());
}


void uiGraphDigitizer::scaleImage (float factor)
{
    Q_ASSERT (ui.imageLabel->pixmap ());
    float scaleFactor = ui.imageLabel->scaleImage(factor);

    adjustScrollBar (ui.scrollArea->horizontalScrollBar (), factor);
    adjustScrollBar (ui.scrollArea->verticalScrollBar (), factor);

    ui.actionZoom_In->setEnabled (scaleFactor < 3.0);
    ui.actionZoom_Out->setEnabled (scaleFactor > 0.333);
}


void uiGraphDigitizer::adjustScrollBar (QScrollBar *scrollBar, float factor)
{
    scrollBar->setValue (int (factor * scrollBar->value ()
                              + ((factor - 1) * scrollBar->pageStep () / 2)));
}

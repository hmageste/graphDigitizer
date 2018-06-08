#include "uiGraphDigitizer.h"
#include <QtWidgets/QApplication>
#include <QtCore/QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName (uiGraphDigitizer::tr ("Graph Digitizer"));
    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption ();
    commandLineParser.addPositionalArgument (uiGraphDigitizer::tr ("[file]"), uiGraphDigitizer::tr ("Image file to open."));
    commandLineParser.process (QCoreApplication::arguments ());
    
    uiGraphDigitizer uiGraphDigitizer;
    if (!commandLineParser.positionalArguments ().isEmpty ()
        && !uiGraphDigitizer.loadFile (commandLineParser.positionalArguments ().front ())) {
        return -1;
    }
    uiGraphDigitizer.show();
    return app.exec();
}

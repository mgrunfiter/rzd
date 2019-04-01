#include "mainwindow.h"


// Данные для ведения логов
static QFile* logFile;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Под Windows устанавливаем кодировку cp1251
    #ifdef Q_WS_WIN
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    // Под остальными ОС - utf8
    #else
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    #endif

    logFile = new QFile(LOG_NAME);
    // Открываем файл логирования
    logFile->open(QFile::Append | QFile::Text);
    // Устанавливаем обработчик
    qInstallMessageHandler(messageHandler);
    qInfo() << "Programm starting";

    MainWindow w;

    w.show();

    return a.exec();
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // Открываем поток записи в файл
    QTextStream out(logFile);
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    switch (type)
    {
        case QtInfoMsg:     out << "INF "; break;
        case QtDebugMsg:    out << "DBG "; break;
        case QtWarningMsg:  out << "WRN "; break;
        case QtCriticalMsg: out << "CRT "; break;
        case QtFatalMsg:    out << "FTL "; break;
    }
    out << context.category << ": " << msg << endl;
    out.flush();
}

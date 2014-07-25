#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

using namespace std;

int main(int argc, char *argv[])
{
    QTranslator translator;
    translator.load("MyProject_en");

    QApplication a(argc, argv);
    a.installTranslator(&translator);

    MainWindow w;

    w.show();



    return a.exec();
}

#include <QApplication>
//#include "mainwindow.h"
#include "tableview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow mw;
//    mw.show();
    TableView tv;
    tv.show();

    return a.exec();
}

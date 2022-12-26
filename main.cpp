#include "start.h"
#include "BusRegister.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //start w;
    start w;
    w.show();
    return a.exec();
}

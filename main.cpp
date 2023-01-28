#include "start.h"
#include "BusRegister.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start w;


   
    /*stream << firstname << "," << lastname << "," << gender << "," <<
        date_of_birth;*/
    /*
    WHAT DO I NEED?

    INSERT BUSES INTO A TABLE 
    INSERT TRIPS INTO A TABLE `
    RETRIEVE THEM USING SELECT
    DELETE THEM USING DELETEh
    */

    w.show();
    return a.exec();
}

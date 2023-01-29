#include "mydatabase.h"
#include <qmessagebox.h>
#include <QtSql/qtsqlglobal.h>
#include <QSqlDatabase> 
#include "TripRegister.h"
#include <QSqlQuery>
#include <QFile> 
#include <QSqlError> 
#include "msgbox.h"

mydatabase::mydatabase() {
	database = QSqlDatabase::addDatabase("QPSQL");
	database.setHostName("localhost");
	database.setDatabaseName("Voyage");
	database.setPort(5432);
	database.setUserName("postgres");
	database.setPassword("password");
	bool ok = database.open();
	if (!ok) {
		MsgBox::showMessage("database didn't open", "Please check the database settings", "black");
		return;
	}
}

void mydatabase::SelectTripByID(int ID, ShowTrips window) {
	QSqlQuery query;

	query.prepare("SELECT * FROM trips WHERE id = " + QString::number(ID)); //SELECT * FROM known_users WHERE email_address = ':email'
	bool ok = query.exec();

	if (!ok) {
		MsgBox::showMessage("Query failed", "Your query failed to execute", "black");
		return;
	}
	// if trip doesn't exist
	if (!query.size()) {
		MsgBox::showMessage("Trip not found", "No trip exists with such ID", "black");
		return;
	}
	//query.bindValue(0, ID);
	//int fieldNo = query.record().indexOf("arrival");
	QFile file("mytest.txt");
	file.open(QIODevice::ReadWrite);
	QTextStream stream(&file);

	while (query.next()) {

		id = query.value(0).toString();
		from = query.value(1).toString();
		to = query.value(2).toString();
		departure = query.value(3).toString();
		arrival = query.value(4).toString();
		drivername = query.value(5).toString();
		//stream << id << "," << firstname << "," << lastname << "," << gender << "," << date_of_birth << "\n";
		stream << id << "," << from << "," << to << "," << departure << "," <<  arrival << "," << drivername;
		file.close();
	}
	database.close();

}
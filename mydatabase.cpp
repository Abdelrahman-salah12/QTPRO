#include "mydatabase.h"
#include <qmessagebox.h>
#include <QtSql/qtsqlglobal.h>
#include <QSqlDatabase> 
#include "TripRegister.h"
#include <QSqlQuery>
#include <QFile> 
#include <QSqlError> 
#include "msgbox.h"
#include <qstring.h>
#include <qsqlrecord.h>



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

	query.prepare("SELECT * from trips WHERE id = " + QString::number(ID)); //SELECT * from known_users WHERE email_address = ':email'
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

void mydatabase::InsertTrip(int id, QString station, QString destination, QString departure,
							QString arrival, QString drivername)
{
	QSqlQuery query;
	query.prepare("INSERT INTO trips (id, station, destination, departure, arrival, drivername) "
				"VALUES (:id, :station, :destination, :departure, :arrival, :drivername)");
	query.bindValue(":id", id);
	query.bindValue(":station", station);
	query.bindValue(":destination", destination);
	query.bindValue(":departure", departure);
	query.bindValue(":arrival", arrival);
	query.bindValue(":drivername", drivername);
	bool ok = query.exec();
	QString text = query.lastError().text();

	if (!ok) {
		MsgBox::showMessage("Insert Error", text, "black");
	}
	else {
		MsgBox::showMessage("Sucess", "Database trips have been edited sucessfully", "black");
	}

}


int mydatabase::NextID() {
	QSqlQuery query;
	query.prepare("SELECT last_value FROM trips_id_seq;");

	//query.prepare("SELECT COUNT(*) FROM :table ");
	//query.bindValue(0, table);

	bool ok = query.exec();
	if (!ok) {
		MsgBox::showMessage("TotalRecords Error", query.lastError().text(), "black");
	}
	query.first();

	//MsgBox::showMessage("summing Error", query.lastError().text(), "black");
	
	return query.value(0).toInt() + 1;
}

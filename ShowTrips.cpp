#include "ShowTrips.h"
#include "BusRegister.h"
#include <fstream>
#include "Bus.h"
#include <QSqlDatabase> 
#include <QSqlQuery> 
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include "mydatabase.h"
#include <qsqlerror.h>

ShowTrips::ShowTrips(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//to acces triplist [static vector of trips]

	
}

void ShowTrips::showEvent(QShowEvent* event) {
	//hide labels
	setVisibility(false);
	ui.Show->setVisible(true);
}


ShowTrips::~ShowTrips()
{}



void ShowTrips::on_Show_clicked() {
	resetLabels();
	// Retrieve data
	updateLabels();
	//show the labels
	setVisibility(true);

}

void ShowTrips::on_Return_clicked() {
	this->hide();
	emit sgnShow();
	resetLabels();
}

void ShowTrips::setVisibility(bool isVisible) {
	ui.labtripid->setVisible(isVisible);
	ui.labbusid->setVisible(isVisible);
	ui.labdriver->setVisible(isVisible);
	ui.labfrom->setVisible(isVisible);
	ui.labto->setVisible(isVisible);
	ui.labarrival->setVisible(isVisible);
	ui.labdeparture->setVisible(isVisible);
}


void ShowTrips::updateLabels() {
	mydatabase db;
	db.SelectTripByID(ui.inputID->value(), this);

	ui.labtripid->setText(ui.labtripid->text() + db.id);

	ui.labbusid->setText(ui.labbusid->text());

	ui.labdeparture->setText(ui.labdeparture->text() + db.departure);

	ui.labarrival->setText(ui.labarrival->text() + db.arrival);

	ui.labfrom->setText(ui.labfrom->text() + db.from);

	ui.labto->setText(ui.labto->text() + db.to);

	ui.labdriver->setText(ui.labdriver->text() + db.drivername);
}


void ShowTrips::closeEvent(QCloseEvent* event)
{
	resetLabels();
	//?
	this->close();
	emit sgnShow();
	event->accept();
}


void ShowTrips::resetLabels() {
	ui.labtripid->setText("tripID: ");
	ui.labbusid->setText("busID: ");
	ui.labdriver->setText("Driver: ");
	ui.labfrom->setText("from: ");
	ui.labto->setText("to: ");
	ui.labarrival->setText("Arrival date: ");
	ui.labdeparture->setText("Departure date: ");
}


void ShowTrips::SelectQuery(int ID) {
	//QString id, firstname, lastname, gender, date_of_birth;
	//QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
	//database.setHostName("localhost");
	//database.setDatabaseName("mydb");
	//database.setPort(5432);
	//database.setUserName("postgres");
	//database.setPassword("password");
	//bool ok = database.open();
	//if (!ok) {
	//	QMessageBox::information(this, "Not connected", "connection failed");
	//}

	//QSqlQuery query;
	//
	//query.prepare("SELECT * FROM Person WHERE id = " + QString::number(ID));
	////query.bindValue(0, ID);
	//query.exec();
	//QFile file("mytest.txt");
	//file.open(QIODevice::ReadWrite);
	//QTextStream stream(&file);
	////int fieldNo = query.record().indexOf("first_name");
	//while (query.next()) {

	//	id = query.value(0).toString();
	//	firstname = query.value(1).toString();
	//	lastname = query.value(2).toString();
	//	gender = query.value(3).toString();
	//	date_of_birth = query.value(4).toString();
	//	stream << id << "," << firstname << "," << lastname << "," << gender << "," << date_of_birth << Qt::endl;

	//	//stream << firstname;
	//}
	//database.close();
	
}

/*std::ofstream myfile;
	myfile.open("show.csv", std::ios::app);
	myfile << trip->triplist[0].getTripID() << ',';
	myfile << trip->triplist[0].getbusID() << ',';
	myfile << trip->triplist[0].getDriver() << ',';
	myfile << trip->triplist[0].getFrom() << ',';
	myfile << trip->triplist[0].getTo() << ',' ;
	myfile << trip->triplist[0].getDepart() << ',' ;
	myfile << trip->triplist[0].getArrival() << ',' << std::endl;
	myfile.close();*/
#include "TripRegister.h"
#include "BusRegister.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "Trip.h"
#include "msgbox.h"
#include "mydatabase.h"
#include <qstring.h>
#include <qfile.h>

std::vector<Trip> TripRegister::triplist;


TripRegister::TripRegister(QWidget *parent)
	: QMainWindow(parent), trip(nullptr)
{
	ui.setupUi(this);
	ui.tripid->setReadOnly(true);
	mydatabase db;
	//MsgBox::showMessage("Trip!", "Trip windows has just opened", "black");
}

void TripRegister::showEvent(QShowEvent* event) {
	trip = new Trip;
	int nextID = mydatabase::NextID();
	ui.tripid->setValue(nextID);
}


void TripRegister::closeEvent(QCloseEvent* event)
{
	clearFields();
	trip = NULL;
	delete trip;
	emit sgnShow();
	event->accept();
}


TripRegister::~TripRegister()
{}



void TripRegister::on_Return_clicked() {
	//THIS iS RETURN BUTTON
	//shows main window, closes sub window
	clearFields();
	this->close();
	emit sgnShow();
}


void TripRegister::on_Submit_clicked() {
	//set the the members of the trip class to the value in the forum
	setValues();
	// if inputs invalid return
	if (!trip->checkInputs()) {
		MsgBox::showMessage("Input Error", "Please make sure to fill all the inputs first", "black");
		return;
	}
	
	mydatabase db;
	db.InsertTrip(trip->getTripID(), trip->getFrom(), trip->getTo(), trip->getDepart(),
				  trip->getArrival(), trip->getDriver());
	//add trip object
	//this->triplist.push_back(*trip);
	//close
	/*this->close();
	emit sgnShow();*/
	addToExcel();
	clearFields();
	int nextID = mydatabase::NextID();
	ui.tripid->setValue(nextID);
}

void TripRegister::clearFields() {
	ui.tripid->setValue(0);
	ui.busid->setValue(0);
	ui.inputdriver->clear();
	ui.inputfrom->clear();
	ui.inputto->clear();
	ui.inputdeparture->clear();
	ui.inputarrival->clear();
}

void TripRegister::addToExcel() {
	QFile myfile("Trips.csv");
	myfile.open(QIODevice::ReadWrite);
	QTextStream stream;
	stream << trip->getTripID() << ',';
	stream << trip->getbusID() << ',';
	stream << trip->getDriver() << ',';
	stream << trip->getFrom() << ',';
	stream << trip->getTo() << ',';
	stream << trip->getArrival() << ',';
	stream << trip->getDepart() << ',' << Qt::endl;
	myfile.flush();
	myfile.close();
}


void TripRegister::setValues() {
	trip->settripID(ui.tripid->value());

	trip->setbusID(ui.busid->value());

	trip->setDriver(ui.inputdriver->toPlainText());

	trip->setFrom(ui.inputfrom->toPlainText());

	trip->setTo(ui.inputto->toPlainText());

	QString arrival = ui.inputarrival->toPlainText();
	trip->setArrival(arrival);

	QString depart = ui.inputdeparture->toPlainText();
	trip->setDepart(depart);
}



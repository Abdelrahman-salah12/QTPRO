#include "TripRegister.h"
#include "BusRegister.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "Trip.h"


std::vector<Trip> TripRegister::triplist;


TripRegister::TripRegister(QWidget *parent)
	: QMainWindow(parent), trip(nullptr)
{
	ui.setupUi(this);
}

void TripRegister::showEvent(QShowEvent* event) {
	trip = new Trip;
	
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
	bool check = false;

	//set the the attributes of the class to their final value as a string
	setValues();
	check = trip->checkInputs();
	if (! (trip->checkInputs()) ) {
		return;
	}
	addToExcel();
	//add trip object
	this->triplist.push_back(*trip);
	//hide
	this->close();
	emit sgnShow();
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
	std::ofstream myfile;
	myfile.open("Trip.csv", std::ios::app);
	myfile << trip->getTripID() << ',';
	myfile << trip->getbusID() << ',';
	myfile << trip->getDriver() << ',';
	myfile << trip->getFrom() << ',';
	myfile << trip->getTo() << ',';
	myfile << trip->getArrival() << ',';
	myfile << trip->getDepart() << ',' << std::endl;
	myfile.flush();
	myfile.close();
}


void TripRegister::setValues() {
	trip->settripID(ui.tripid->value());

	trip->setbusID(ui.busid->value());

	trip->setDriver(ui.inputdriver->toPlainText().toStdString());

	trip->setFrom(ui.inputfrom->toPlainText().toStdString());

	trip->setTo(ui.inputto->toPlainText().toStdString());

	std::string arrival = ui.inputarrival->toPlainText().toStdString();
	trip->setArrival(arrival);

	std::string depart = ui.inputdeparture->toPlainText().toStdString();
	trip->setDepart(depart);
}



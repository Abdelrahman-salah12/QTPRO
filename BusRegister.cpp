#include "BusRegister.h"
#include "start.h"
#include <QCloseEvent>
#include <iostream>
#include <QDebug>
#include <QShowEvent>
#include "Bus.h"
#include <fstream>
#include <qmessagebox.h>

std::vector<Bus> BusRegister::buslist;


BusRegister::BusRegister(QWidget *parent)
	: QMainWindow(parent), bus(nullptr)
{
	ui.setupUi(this);
	//change after excel, read the last bus then return + 1
}


void BusRegister::showEvent(QShowEvent* event) {
	bus = new Bus();
	bus->setID(0);
	bus->setSeats(0);
	ui.input_seats->setValue(0);
}


BusRegister::~BusRegister()
{}


void BusRegister::on_Return_clicked() {
	this->hide();
	emit sgnShow();
}

void BusRegister::on_Submit_clicked() {
	//Submit button
	//
	bus->setSeats(ui.input_seats->value());
	if (bus->getSeats() < 20 || bus->getSeats() > 40) {
		return;
	}
	bus->setID(ui.busID->value());

	for (int i = 0; i < buslist.size(); i++) {
		if (bus->getID() == buslist[i].getID())
		{
			QMessageBox::information(this, tr("Error XD"), tr("There is a bus with this ID pick another one"));
			return;
		}
	}
	initialize_seats(bus->getSeats());
	buslist.push_back(*bus);
	// waheed, hta5od kol values ely hna w t7otha fy table Trip fy excel w t7ot kol el byanat bdl el txt file
	std::ofstream myfile;
	myfile.open("Bus.csv", std::ios::app);
	myfile << bus->getID() << ',';
	myfile << bus->getSeats() << ',' << std::endl;
	myfile.flush();
	myfile.close();
	sgnShow();
	this->close();
	return;
	
	//more
}



void BusRegister::closeEvent(QCloseEvent* event)
{
	emit sgnShow();
	event->accept();
}


void BusRegister::initialize_seats(int size) {
	for (int i = 0; i < size; i++) {
		bus->totalseats.push_back(0);
	}
}


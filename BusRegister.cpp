#include "BusRegister.h"
#include "start.h"
#include <QCloseEvent>
#include <iostream>
#include <QDebug>

int BusRegister::buscount;

BusRegister::BusRegister(QWidget *parent)
	: QMainWindow(parent), id(-1)
{
	ui.setupUi(this);
	buscount += 1;
	//change after excel
	QString text = ui.L_busid->text();
	text += QString::number(buscount);
	ui.L_busid->setText(text);
}

BusRegister::~BusRegister()
{}

// connect the signal/slot

// when you clicked the button, emit the signal "sgnShow"
void BusRegister::on_Return_clicked() {
	//THIS iS RETURN BUTTON
	//shows main window, closes sub window
	this->hide();
	emit sgnShow();
}

void BusRegister::on_Submit_clicked() {
	//Submit button
	int max = ui.input_seats->value();
	
	if (max >= 20 && max <= 40) {
		initialize_seats(max);
		sgnShow();
		this->close();
		return;
	}
	//more
}

void BusRegister::closeEvent(QCloseEvent* event)
{
	emit sgnShow();
	event->accept();
	delete m_bus;
}


void BusRegister::initialize_seats(int size) {
	for (int i = 0; i < size; i++) {
		totalseats.push_back(0);
	}
}

void BusRegister::setID(int id) {
	this->id = id;
}

//Initialize numof seats and declare them to 0, 0 = still available for booking.
void BusRegister::setSeats(int index) {
	totalseats[index] = 1;
	//cout << seats.size();
}

int BusRegister::getID() {
	return this->id;
}
//returns a specific seat in seats[]
std::vector<int> BusRegister::getSeats() {
	return this->totalseats;
}
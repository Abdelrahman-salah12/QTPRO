#include "Trip.h"

//setters
Trip::Trip() {
	this->busID = 0;
	this->tripID = 0;
}
void Trip::setTo(QString to) {
	this->to = to;
}
void Trip::setUser(QString user) {
	this->user = user;
}
void Trip::setFrom(QString from) {
	this->from = from;
}
void Trip::setArrival(QString arrival) {
	this->arrival = arrival;
}
void Trip::setDepart(QString depart) {
	this->depart = depart;
}
void Trip::setDriver(QString driver) {
	this->drivername = driver;
}
//getters
QString Trip::getTo() {
	return this->to;
}
QString Trip::getFrom() {
	return this->from;
}
QString Trip::getArrival() {
	return this->arrival;
}
QString Trip::getDepart() {
	return this->depart;
}
QString Trip::getDriver() {
	return this->drivername;
}
QString Trip::getUser() {
	return this->user;
}
int Trip::getTripID() {
	return this->tripID;
}

int Trip::getbusID() {
	return this->getTripID();
}

void Trip::setbusID(int busID) {
	this->busID = busID;
};
void Trip::settripID(int tripID) {
	this->tripID = tripID;
};

bool Trip::checkInputs() {
	if (busID == 0)
		return false;
	else if (drivername == "")
		return false;
	else if (from == "")
		return false;
	else if (to == "")
		return false;
	else if (arrival == "")
		return false;
	else if (depart == "")
		return false;
	return true;
}
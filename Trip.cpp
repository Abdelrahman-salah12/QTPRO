#include "Trip.h"

//setters
Trip::Trip() {
	this->busID = 0;
	this->tripID = 0;
}
void Trip::setTo(std::string to) {
	this->to = to;
}
void Trip::setUser(std::string user) {
	this->user = user;
}
void Trip::setFrom(std::string from) {
	this->from = from;
}
void Trip::setArrival(std::string arrival) {
	this->arrival = arrival;
}
void Trip::setDepart(std::string depart) {
	this->depart = depart;
}
void Trip::setDriver(std::string driver) {
	this->drivername = driver;
}
//getters
std::string Trip::getTo() {
	return this->to;
}
std::string Trip::getFrom() {
	return this->from;
}
std::string Trip::getArrival() {
	return this->arrival;
}
std::string Trip::getDepart() {
	return this->depart;
}
std::string Trip::getDriver() {
	return this->drivername;
}
std::string Trip::getUser() {
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
	if (tripID == 0)
		return false;
	else if (busID == 0)
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
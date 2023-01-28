#include "Bus.h"

void Bus::setID(int busid) {
	this->busid = busid;
}

void Bus::setSeats(int seats) {
	this->seats = seats;
}

int Bus::getID() {
	return this->busid;
}
//returns a specific seat in seats[]
int Bus::getSeats() {
	return this->seats;
}
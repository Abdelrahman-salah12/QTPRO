#pragma once
#include <string>
#include <vector>
#include <qstring.h>


class Trip
{
public:
	std::vector<int> seats;
	Trip();
	//Setters 
	void setTo(QString to);
	void setUser(QString user);
	void setFrom(QString from);
	void setArrival(QString arrival);
	void setDepart(QString depart);
	void setDriver(QString driver);
	void setbusID(int busID);
	void settripID(int tripID);
	//Getters
	QString getTo();
	QString getUser();
	QString getFrom();
	QString getArrival();
	QString getDepart();
	QString getDriver();
	int getTripID();
	int getbusID();
	bool checkInputs();
	//Methods

private:
	QString from, to, arrival, depart, drivername, user;
	int busID, tripID;
};


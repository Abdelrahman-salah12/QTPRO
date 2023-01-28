#pragma once
#include <string>
#include <vector>
class Trip
{
public:
	std::vector<int> seats;
	Trip();
	//Setters 
	void setTo(std::string to);
	void setUser(std::string user);
	void setFrom(std::string from);
	void setArrival(std::string arrival);
	void setDepart(std::string depart);
	void setDriver(std::string driver);
	void setbusID(int busID);
	void settripID(int tripID);
	//Getters
	std::string getTo();
	std::string getUser();
	std::string getFrom();
	std::string getArrival();
	std::string getDepart();
	std::string getDriver();
	int getTripID();
	int getbusID();
	bool checkInputs();
	//Methods

private:
	std::string from, to, arrival, depart, drivername, user;
	int busID, tripID;
};


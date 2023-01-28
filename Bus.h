#pragma once

#include <vector>
class Bus {
public:
	std::vector<int> totalseats;
	void setID(int busid);
	void setSeats(int seats);
	int getID();
	int getSeats();

private:
	int busid;
	int seats;
};
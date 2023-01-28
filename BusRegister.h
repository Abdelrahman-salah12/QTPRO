#pragma once
#ifndef BUS_REGISTER_H
#define BUS_REGISTER_H

#include <QMainWindow>
#include <QObject>
#include "ui_BusRegister.h"
#include <QCloseEvent>
#include <QShowEvent>
#include <vector>
#include "Bus.h"
#include <fstream>
class BusRegister : public QMainWindow
{
	Q_OBJECT;

public:
	
	BusRegister(QWidget *parent = nullptr);
	~BusRegister();
	Bus *bus;
	static std::vector<Bus> buslist;





	//Registers the bus ID and the number of seats inside the bus
	void Register(int id);
	void setID(int id);
	//initialize every seat in seats to 0
	void setSeats(int index);
	void initialize_seats(int size);
	int getID();
	
	std::vector<int> getSeats();


signals:
	void sgnShow();
	void sgnOpen();

private slots:
	void on_Return_clicked();
	void on_Submit_clicked();

	void closeEvent(QCloseEvent* event);
	void showEvent(QShowEvent* event);

private:
	Ui::BusRegisterClass ui;
	// to check for id

};


#endif

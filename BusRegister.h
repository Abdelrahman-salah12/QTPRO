#pragma once
#ifndef BUS_REGISTER_H
#define BUS_REGISTER_H

#include <QMainWindow>
#include <QObject>
#include "ui_BusRegister.h"
#include <QCloseEvent>
#include <vector>
class BusRegister : public QMainWindow
{
	Q_OBJECT;
	static int buscount;

public:
	BusRegister(QWidget *parent = nullptr);
	~BusRegister();

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

private:
	Ui::BusRegisterClass ui;
	int id;
	std::vector<int> totalseats;
};


#endif

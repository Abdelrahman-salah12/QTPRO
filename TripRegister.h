#pragma once

#include <QMainWindow>
#include "ui_TripRegister.h"
#include "BusRegister.h"
#include <iostream>
#include <vector>
#include "Trip.h"


class TripRegister : public QMainWindow
{
	Q_OBJECT

public:
	TripRegister(QWidget *parent = nullptr);
	~TripRegister();
	static std::vector<Trip> triplist;
	Trip* trip;

	void showTrip();

signals:
	void sgnShow();

private:
	Ui::TripRegisterClass ui;
	void clearFields();
	void addToExcel();
	void setValues();

private slots:
	void on_Return_clicked();
	void on_Submit_clicked();
	void showEvent(QShowEvent* event);
	void closeEvent(QCloseEvent* event);
	
};

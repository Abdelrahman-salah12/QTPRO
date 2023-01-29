#pragma once

#include <QMainWindow>
#include "ui_ShowTrips.h"
#include "BusRegister.h"
#include "TripRegister.h"
class ShowTrips : public QMainWindow
{
	Q_OBJECT

public:
	ShowTrips(QWidget *parent = nullptr);
	~ShowTrips();
	TripRegister* trip;
signals:
	void sgnShow();
	void sgnOpen();

private slots:
	void on_Show_clicked();
	void on_Return_clicked();
	void showEvent(QShowEvent* event);
	void closeEvent(QCloseEvent* event);

	

private:
	Ui::ShowTripsClass ui;
	void setVisibility(bool isVisible);
	void updateLabels();
	void resetLabels();
	void SelectQuery(int ID);
};

#pragma once
#ifndef START_H
#define START_H

#include <QtWidgets/QMainWindow>
#include <QObject>
#include "ui_start.h"
#include "BusRegister.h"
#include "TripRegister.h"
#include "ShowTrips.h"

class start : public QMainWindow
{
    Q_OBJECT

public:
    start(QWidget *parent = nullptr);
    ~start();
    static std::vector<BusRegister> totalbuses;
    std::vector<TripRegister> totaltrips;
    
private slots:
    void on_BusRegistration_clicked();
    void on_TripRegistration_clicked();
    void on_ShowTrip_clicked();


private:
    Ui::startClass ui;
    BusRegister* m_bus;
    TripRegister* tripReg;
    ShowTrips* trip_show;
signals:
    void on_Return_clicked();

};

#endif
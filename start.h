#pragma once
#ifndef START_H
#define START_H

#include <QtWidgets/QMainWindow>
#include <QObject>
#include "ui_start.h"
#include "BusRegister.h"


class start : public QMainWindow
{
    Q_OBJECT

public:
    start(QWidget *parent = nullptr);
    ~start();
private slots:
    void on_BusRegistration_clicked();
private:
    Ui::startClass ui;
    BusRegister* m_bus;

signals:
    void on_Return_clicked();

};

extern start w;
#endif
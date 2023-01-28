#include "start.h"
#include "BusRegister.h"
#include <QCloseEvent>
#include "TripRegister.h"

start::start(QWidget* parent)
    : QMainWindow(parent) , m_bus(new BusRegister), tripReg(new TripRegister), trip_show(new ShowTrips)
{
    ui.setupUi(this);
    //Return button on BusRegister clicked -> show main window
    connect(m_bus, &BusRegister::sgnShow, this, &start::show);
    //if busRegister window is closed by X button -> show start window
    connect(m_bus, &BusRegister::sgnShow, this, &start::show);
    //TripReg
    connect(tripReg, &TripRegister::sgnShow, this, &start::show);

    connect(trip_show, &ShowTrips::sgnShow, this, &start::show);
    //closes application upon clicking exit
    connect(ui.Exit, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);


}

start::~start()
{}


//On click functions 


void start::on_BusRegistration_clicked() {
    
    m_bus->show();
    this->hide();
}


void start::on_TripRegistration_clicked() {
    
    tripReg->show();
    this->hide();
}


void start::on_ShowTrip_clicked() {
    trip_show->show();
    this->hide();
};





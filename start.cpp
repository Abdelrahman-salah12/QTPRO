#include "start.h"
#include "BusRegister.h"
#include <QCloseEvent>

start::start(QWidget* parent)
    : QMainWindow(parent) , m_bus(new BusRegister)
{
    
    m_bus->setAttribute(Qt::WA_DeleteOnClose);
    ui.setupUi(this);
    //Return button on BusRegister clicked -> show main window
    connect(m_bus, &BusRegister::sgnShow, this, &start::show);
    //if busRegister window is closed by X button -> show start window
    connect(m_bus, &BusRegister::sgnShow, this, &start::show);

}

start::~start()
{}

void start::on_BusRegistration_clicked() {
    //hides main window, shows sub window
    
    m_bus->show();
    this->hide();
}


#pragma once
#include <QString> 
#include "ShowTrips.h"
#include <qsqldatabase.h>
#include <qsqlquery.h>

class mydatabase
{
public:
	mydatabase();
	void SelectTripByID(int ID, ShowTrips window);
	//encapsulate?
	QSqlDatabase database;
	QString id, from, to, departure, arrival, drivername;


};


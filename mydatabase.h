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
	void InsertTrip(int id, QString from, QString to, QString departure,
					QString arrival, QString drivername);

	static int NextID();
	//encapsulate?
	QSqlDatabase database;
	QString id, from, to, departure, arrival, drivername;


};


#pragma once
#include <qmessagebox.h>
#include <qstring.h>

class MsgBox
{
public:
	static void showMessage(QString title, QString text, QString color);
};


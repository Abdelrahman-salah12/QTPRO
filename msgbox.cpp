#include "msgbox.h"

void MsgBox::showMessage(QString title, QString text, QString color)
{
	QMessageBox msg;
	msg.setText(text);
	msg.setWindowTitle(title);
	msg.setStyleSheet("color: " + color);
	msg.exec();
}

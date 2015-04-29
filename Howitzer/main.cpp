#include "gungui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GunGui w;
	w.show();

	return a.exec();
}

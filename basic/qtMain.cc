#include <QCoreApplication>
#include <QThread>
#include "QObjectSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	QThread thread;

	QObjectSubclass qObjectSublass;

	qObjectSubclass.moveToThread(&thread);

	thread.start();

	thread.quit();
	thread.wait();

	return 0;

}


#include <QCoreApplication>
#include <QThread>
#include "QObjectSubclass.h"
#include "QThreadSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	QThread thread;

	QObjectSubclass qObjectSublass;

	qObjectSubclass.moveToThread(&thread);

	QThreadSubclass qThreadSubclass;

	thread.start();
	qThreadSubclass.start();

	thread.quit();
	thread.wait();

	//Do not need to quit because the reimplemented run function will
	//terminate on its own
	qThreadSubclass.wait();

	return 0;

}


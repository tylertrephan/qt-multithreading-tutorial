#include <iostream>
#include <unistd.h>
#include <QCoreApplication>
#include <QThread>
#include <QObject>
#include "QThreadSubclass.h"
#include "QObjectSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	std::cout<<"qtMain::Creating QThreadSubclass"<<std::endl;;
	QThreadSubclass qThreadSubclass;

	std::cout<<"qtMain::Creating Worker QObjectSubclass1"<<std::endl;;
	QObjectSubclass qObjectSubclass1(1);
	std::cout<<"qtMain::Creating Worker QObjectSubclass2"<<std::endl;;
	QObjectSubclass qObjectSubclass2(2);
	std::cout<<"qtMain::Creating Worker QObjectSubclass3"<<std::endl;;
	QObjectSubclass qObjectSubclass3(3);

	std::cout<<"qtMain::Creating QThread"<<std::endl;;
	QThread thread;

	std::cout<<"qtMain::Moving qObjectSubclass3 to QThread"<<std::endl;;
	qObjectSubclass3.moveToThread(&thread);

	std::cout<<"qtMain::Connecting qThreadSubclass's signal to \n"
		 <<"        qObjectSubclass1's slot as a queued connection"
		 <<std::endl;;
	QObject::connect(&qThreadSubclass,
			 SIGNAL(simpleSignal(unsigned int)),
			 &qObjectSubclass1,
			 SLOT(sendSignalSlot(unsigned int)));

	std::cout<<"qtMain::Connecting qObjectSubclass1's signal to \n"
		 <<"        qObjectSubclass2's slot as a direct connection"
		 <<std::endl;;
	//Qt allows connections as long as the # Signal parameters are >= the #
	//of Slot parameters
	QObject::connect(&qObjectSubclass1,
			 SIGNAL(simpleSignal(unsigned int)),
			 &qObjectSubclass2,
			 SLOT(simpleSlot()));

	std::cout<<"qtMain::Connecting qObjectSubclass1's signal to \n"
		 <<"        qObjectSubclass3's slot as a queued connection"
		 <<std::endl;;
	//Qt allows signals to connect to multiple slots
	QObject::connect(&qObjectSubclass1,
			 SIGNAL(simpleSignal(unsigned int)),
			 &qObjectSubclass3,
			 SLOT(sleepSlot(unsigned int )));

	std::cout<<"qtMain::Connecting qObjectSubclass3's signal to \n"
		 <<"        app's exit slot as a queued connection"
		 <<std::endl;;
	QObject::connect(&qObjectSubclass3,
			 SIGNAL(finished()),
			 &app,
			 SLOT(quit()));

	std::cout<<"qtMain::Starting qObjectSubclass3's QThread"<<std::endl;
	thread.start();

	std::cout<<"qtMain::Starting qThreadSubclass"<<std::endl;
	qThreadSubclass.start();

	//Start main app's event loop and waits until quit() is called
	std::cout<<"qtMain::Starting Main Event Loop - app.exec()"<<std::endl;
	app.exec();

	std::cout<<"qtMain::Quiting qObjectSubclass3's QThread"<<std::endl;;
	thread.quit();

	std::cout<<"qtMain::Waiting qObjectSubclass3's QThread"<<std::endl;;
	thread.wait();

	std::cout<<"qtMain::Waiting qThreadSubclass"<<std::endl;
	qThreadSubclass.wait();

	std::cout<<"qtMain::Finished"<<std::endl;
	return 0;

}


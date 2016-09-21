#include <iostream>
#include <unistd.h>
#include <QCoreApplication>
#include <QObject>
#include <QThread>
#include "QObjectSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	std::cout<<"qtMain::Creating Worker QObjectSubclass1"<<std::endl;;
	QObjectSubclass qObjectSubclass1(1);
	std::cout<<"qtMain::Creating Worker QObjectSubclass2"<<std::endl;;
	QObjectSubclass qObjectSubclass2(2);

	std::cout<<"qtMain::Creating QThread"<<std::endl;;
	QThread thread;

	std::cout<<"qtMain::Moving qObjectSubclass2 to QThread"<<std::endl;;
	qObjectSubclass2.moveToThread(&thread);

	std::cout<<"qtMain::Connecting qObjectSubclass1's signal to \n"
		 <<"        qObjectSubclass2's slot as a queued connection"
		 <<std::endl;;
	QObject::connect(&qObjectSubclass1,
			 SIGNAL(simpleSignal(unsigned int)),
			 &qObjectSubclass2,
			 SLOT(simpleSlot(unsigned int)));

	std::cout<<"qtMain::Starting qObjectSubclass2's QThread"<<std::endl;
	thread.start();
	
	std::cout<<"qtMain::qObjectSubclass1 simpleFunction()"<<std::endl;;
	qObjectSubclass1.simpleFunction();

	//Hack to give qThreadSubclass2 enough time to finish
	sleep(5);

	std::cout<<"qtMain::Quiting qObjectSubclass2's QThread"<<std::endl;;
	thread.quit();

	std::cout<<"qtMain::Waiting qObjectSubclass2's QThread"<<std::endl;;
	thread.wait();

	std::cout<<"qtMain::Finished"<<std::endl;
	return 0;

}


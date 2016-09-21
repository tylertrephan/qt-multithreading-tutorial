#include <iostream>
#include <unistd.h>
#include <QCoreApplication>
#include <QObject>
#include "QObjectSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	std::cout<<"qtMain::Creating Worker QObjectSubclass1"<<std::endl;;
	QObjectSubclass qObjectSubclass1(1);
	std::cout<<"qtMain::Creating Worker QObjectSubclass2"<<std::endl;;
	QObjectSubclass qObjectSubclass2(2);

	std::cout<<"qtMain::Connecting qObjectSubclass1's signal to \n"
		 <<"        qObjectSubclass2's slot as a direct connection"
		 <<std::endl;;
	QObject::connect(&qObjectSubclass1,
			 SIGNAL(simpleSignal(unsigned int)),
			 &qObjectSubclass2,
			 SLOT(simpleSlot(unsigned int)));
	
	std::cout<<"qtMain::qObjectSubclass1 simpleFunction()"<<std::endl;;
	qObjectSubclass1.simpleFunction();

	std::cout<<"qtMain::Finished"<<std::endl;
	return 0;

}


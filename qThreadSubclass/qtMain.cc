#include <iostream>
#include <unistd.h>
#include <QCoreApplication>
#include "QThreadSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	std::cout<<"qtMain::Creating QThreadSubclass"<<std::endl;;
	QThreadSubclass qThreadSubclass;
	
	std::cout<<"qtMain::Starting QThread"<<std::endl;;
	qThreadSubclass.start();

	std::cout<<"qtMain::Sleeping 1 second"<<std::endl;;
	sleep(1);

	std::cout<<"qtMain::Waiting QThread"<<std::endl;;
	qThreadSubclass.wait();

	std::cout<<"qtMain::Finished"<<std::endl;
	return 0;

}


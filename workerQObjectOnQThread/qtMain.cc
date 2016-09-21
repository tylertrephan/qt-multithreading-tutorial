#include <iostream>
#include <unistd.h>
#include <QCoreApplication>
#include <QThread>
#include "QObjectSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	std::cout<<"qtMain::Creating QThread"<<std::endl;;
	QThread thread;

	std::cout<<"qtMain::Creating Worker QObjectSubclass"<<std::endl;;
	QObjectSubclass qObjectSubclass;

	std::cout<<"qtMain::Moving Worker QObjectSubclass to QThread"
		 <<std::endl;;
	qObjectSubclass.moveToThread(&thread);

	
	std::cout<<"qtMain::Starting QThread"<<std::endl;;
	thread.start();

	std::cout<<"qtMain::Sleeping 1 second"<<std::endl;;
	sleep(1);

	std::cout<<"qtMain::Quiting QThread"<<std::endl;;
	thread.quit();

	std::cout<<"qtMain::Waiting QThread"<<std::endl;;
	thread.wait();

	std::cout<<"qtMain::Finished"<<std::endl;
	return 0;

}


#include <iostream>
#include <QCoreApplication>
#include <QThread>
#include "QObjectSubclass.h"

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	std::cout<<"Creating QThread"<<std::endl;;
	QThread thread;

	std::cout<<"Creating Worker QObject"<<std::endl;;
	QObjectSubclass qObjectSubclass;

	std::cout<<"Moving Worker QObject to QThread"<<std::endl;;
	qObjectSubclass.moveToThread(&thread);

	
	std::cout<<"Starting QThread"<<std::endl;;
	thread.start();

	std::cout<<"Quiting QThread"<<std::endl;;
	thread.quit();

	std::cout<<"Waiting QThread"<<std::endl;;
	thread.wait();

	std::cout<<"Finished"<<std::endl;
	return 0;

}


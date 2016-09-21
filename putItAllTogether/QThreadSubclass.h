#ifndef INCLUDED_QTHREADSUBCLASS_H
#define INCLUDED_QTHREADSUBCLASS_H

#include <iostream>
#include <unistd.h>
#include <QThread>

class QThreadSubclass : public QThread
{
	Q_OBJECT

	public:
		// Reimplementation of QThread's run() function
		void run()
		{
			std::cout<<"QThreadSubclass::run()"<<std::endl;
			for(unsigned int i = 1; i <= 5; ++i)
			{
				std::cout<<"QThreadSubclass::sending signal: "
					 <<i
					 <<std::endl;
				emit simpleSignal(i);
				sleep(1);
			}
			std::cout<<"QThreadSubclass::Finished"<<std::endl;
		}

	signals:
		void simpleSignal(unsigned int value);
};
		

#endif // INCLUDED_QTHREADSUBCLASS_H

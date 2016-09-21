#ifndef INCLUDED_QOBJECTSUBCLASS_H
#define INCLUDED_QOBJECTSUBCLASS_H

#include <iostream>
#include <unistd.h>
#include <QObject>

class QObjectSubclass : public QObject
{
	Q_OBJECT

	public:
		QObjectSubclass(unsigned int id = 0)
			: m_id(id) {}

		void simpleFunction()
		{
			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleFunction()"
				 <<std::endl;

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleFunction(): " 
				 <<"emitting signal"
				 <<std::endl;
			emit simpleSignal(3);

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleFunction(): Finished"
				 <<std::endl;
		}
			

	signals:
		void simpleSignal(unsigned int value);
		void finished();

	public slots:
		void simpleSlot()
		{
			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleSlot"
				 <<std::endl;

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleSlot Finished"
				 <<std::endl;
		}

		void sendSignalSlot(unsigned int value)
		{
			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::sendSignalSlot value: "
				 <<value
				 <<std::endl;


			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::sendSignalSlot emitting signal: "
				 <<value
				 <<std::endl;
			emit simpleSignal(value);

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::sendSignalSlot Finished"
				 <<std::endl;
		}


		void sleepSlot(unsigned int value)
		{
			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::sleepSlot value: "
				 <<value
				 <<std::endl;

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::sleepSlot sleeping"
				 <<std::endl;
			sleep(value);

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::sleepSlot Finished"
				 <<std::endl;

			if(5 == value)
			{
				std::cout<<"QObjectSubclass"
				         <<m_id
				         <<"::sleepSlot emitting finished()"
				 	 <<std::endl;
				emit finished();
			}

		}

	private:
		unsigned int m_id;

};
		

#endif // INCLUDED_QOBJECTSUBCLASS_H

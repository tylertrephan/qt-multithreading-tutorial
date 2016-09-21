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

	public slots:

		void simpleSlot(unsigned int value)
		{
			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleSlot value: "
				 <<value
				 <<std::endl;

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleSlot sleeping"
				 <<std::endl;
			sleep(value);

			std::cout<<"QObjectSubclass"
				 <<m_id
				 <<"::simpleSlot Finished"
				 <<std::endl;
		}

	private:
		unsigned int m_id;

};
		

#endif // INCLUDED_QOBJECTSUBCLASS_H

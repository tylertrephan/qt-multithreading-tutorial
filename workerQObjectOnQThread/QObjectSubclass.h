#ifndef INCLUDED_QOBJECTSUBCLASS_H
#define INCLUDED_QOBJECTSUBCLASS_H

#include <iostream>
#include <QObject>

class QObjectSubclass : public QObject
{
	Q_OBJECT

	signals:
		void simpleSignal(unsigned int value);

	public slots:

		void simpleSlot(unsigned int value)
		{
			std::cout<<"QObjectSubclass::simpleSlot value: "
				 <<value
				 <<std::endl;
		}

};
		

#endif // INCLUDED_QOBJECTSUBCLASS_H

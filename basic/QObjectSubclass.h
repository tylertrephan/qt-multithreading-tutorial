#ifndef INCLUDED_QOBJECTSUBCLASS_H
#define INCLUDED_QOBJECTSUBCLASS_H

#include <QObject>

class QObjectSubclass : QObject
{
	Q_OBJECT

	public slots:

		void simpleSlot(unsigned int value)
		{
			std::cout<<"simpleSlot value: "<<value<<std::endl;
		}

};
		

#endif // INCLUDED_QOBJECTSUBCLASS_H

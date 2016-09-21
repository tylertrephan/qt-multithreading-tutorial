#ifndef INCLUDED_QTHREADSUBCLASS_H
#define INCLUDED_QTHREADSUBCLASS_H

#include <QThread>

class QThreadSubclass : QThread
{
	Q_OBJECT

	public:
		// Reimplementation of QThread's run() function
		void run()
		{
			for(unsigned int i = 0; i < 10; ++i)
			{
				emit loopSignal(i);
				sleep(1);
			}
		}

	signals:
		void loopSignal(unsigned int iteration);
};
		

#endif // INCLUDED_QTHREADSUBCLASS_H

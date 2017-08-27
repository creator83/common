#include "dispatcher.h"

Dispatcher::Dispatcher ()
{
	
}

void Dispatcher::addTask (void (*f)(), uint16_t c)
{
	tasks.addFirst (f, c);
}

void Dispatcher::tickTask ()
{
	tasks.iterate();
}

void Dispatcher::checkTasks ()
{
	tasks.current = tasks.head;
	for (uint8_t i=0, c=tasks.getCount() ;i<c; ++i)
	{
		if (tasks.current->getCounter()==0)
			{
				queue.addLast (tasks.current->getPtrF(), tasks.current->getSet());
				tasks.removeCurrItem();
			}
	}
}

void Dispatcher::checkQueue ()
{
	if (queue.getCount())
	{
		queue.head->getPtrF();
		tasks.addLast(queue.head->getPtrF(), queue.head->getSet());
		queue.removeHead ();
	}
}
	






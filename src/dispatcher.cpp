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
	if (tasks.current->getCounter()==0)
	{
		queue.addLast (tasks.current->getPtrF(), tasks.current->getSet());
		tasks.removeCurrItem();
	}
}




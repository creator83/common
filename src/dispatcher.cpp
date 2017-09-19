#include "dispatcher.h"

Dispatcher::Dispatcher ()
{
}

void Dispatcher::addTask (void (*f)(), uint16_t c)
{
	tasks.addLast (f, c);
}

void Dispatcher::tickTask ()
{
	tasks.iterate();
}

void Dispatcher::checkTasks ()
{
	tasks.current = tasks.head;
	while (tasks.current != nullptr)
	{
		if (tasks.current->getCounter()==0)
			{
				queue.addLast (tasks.current->getPtrF(), tasks.current->getSet());
				tasks.removeItem(tasks.current);
			}
			else
			{
				tasks.current = tasks.current->next;
			}
	}
}

void Dispatcher::checkQueue ()
{
	while (queue.getCount())
	{
		queue.head->ptrF();
		tasks.addLast(queue.head->getPtrF(), queue.head->getSet());
		queue.removeItem (queue.head);
	}
}
	






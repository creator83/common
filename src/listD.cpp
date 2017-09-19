#include "listD.h"

List::Item::Item (void (*f)(), uint16_t c, Item * n, Item * p)
	:ptrF(f), next(n), prev (p), counter(c), set(c)
{
}

void List::Item::decrCounter ()
{
	if (counter==0)
		counter = 0;
	else
		counter--;
}

uint16_t & List::Item::getCounter ()
{
	return counter;
}

uint16_t & List::Item::getSet ()
{
	return set;
}

	void (*List::Item::getPtrF(void)) ()
{
	return ptrF;
}

List::List()
{
	count = 0;
	head = tail = current = nullptr;
}

List::~List()
{
	Item * current = nullptr;
	Item * next = head;
	while (next->next != nullptr)
	{
		current = next;
		next = next->next;
		delete current;
	}
	current = tail;
	delete current;
}

void List::addFirst (void (*f)(), uint16_t c)
{
	Item * newItem = new Item (f, c, head);
	if (head == nullptr)
	{
		tail = newItem;
	}
	head = newItem;
	++count;
}

void List::addLast (void (*f)(), uint16_t c)
{
	Item * newItem = new Item (f, c);
	if (head == nullptr)
	{
		head = newItem;
	}
	else
	{
		tail->next = newItem;
		newItem->prev = tail;
	}
	tail = newItem;
	++count;
}

void List::iterate ()
{
	Item * next = head;
	for (uint16_t i=0;i<count;++i)
	{
		next->decrCounter();
		next = next->next;
	}
}

void List::increment ()
{
	if (current->next!=nullptr)
	{
		current = current->next;
	}
	else
	{
		current = head;
	}
}

void List::startCurF ()
{
	current->getPtrF();
}

void List::startItem (Item *i)
{
	i->ptrF();
}

uint16_t & List::getCount ()
{
	return count;
}

void List::removeCurrItem ()
{
	if (current==head)
	{
		removeHead();
	}
	else{
		current->prev->next = current->next;
		delete current;
		
	}
	--count;
	current = current->next;
}

void List::removeItem (Item *i)
{
	if (getCount()==1)
	{
		head = tail = nullptr;
	}
	else
	{
		if (i == head)
		{
			head = head->next;
			current = head;
		}
		else if (i == tail)
		{
			tail = tail->prev;
			current = tail;
			tail->next = nullptr;
		}
		else
		{
			i->prev->next = i->next;
			i->next->prev = i->prev;	
			current = i->next;
		}
			
	}
	
	delete i;
	--count;
}

void List::removeHead ()
{
	Item * cur= head->next;
	delete head;
	--count;	
	head = nullptr;
	if (getCount()==0)//if one element
	{	
		tail->prev = head;
		head->next = tail;
	}
	else
	{
		cur->prev = head;
		head->next = cur;
	}
}


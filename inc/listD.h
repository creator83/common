#include "device.h"


#ifndef LIST_H
#define LIST_H

class List {
class Item
{
	public:
	void (*ptrF)();
	Item * next;
	Item * prev;
	uint16_t counter, set;
	Item (void (*f)(), uint16_t c, Item * n = nullptr,  Item * p = nullptr);
	void decrCounter ();
	uint16_t & getCounter ();
	uint16_t & getSet ();
	void (*getPtrF(void)) ();
};


	uint16_t count;
public:
	Item * head;
	Item * tail;
	Item * current;	
	List();
	~List();
	Item* getHead () const {return head;}
	Item* getTail () const {return tail;}
	Item* getCurrent () const {return current;}
	void addFirst (void (*f)(), uint16_t c);
	void addLast (void (*f)(), uint16_t c);
	
	void iterate ();
	void increment ();
	void startCurF ();
	Item * next ();
	uint16_t & getCount ();
	void removeCurrItem (); 
	void removeHead ();

};



#endif /* LIST_H_ */

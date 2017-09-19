#include "device.h"
#include "listD.h"

#ifndef DISPATCHER_H
#define DISPATCHER_H

class Dispatcher {

private:
	List tasks;
	List queue;

public:
	Dispatcher ();
	void addTask (void (*f)(), uint16_t c);
	void tickTask ();
	void checkTasks ();
	void checkQueue ();
};

#endif /* LIST_H_ */

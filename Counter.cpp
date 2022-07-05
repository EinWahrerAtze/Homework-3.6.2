#include <iostream>
#include "Counter.h"

void Counter::count_up()
{
	++counter;
}

void Counter::count_down()
{
	--counter;
}

int Counter::count_show()
{
	return counter;
}

Counter::Counter(int n)
{
	if (n != 1)
	{
		counter = n;
	}
	else
	{
		counter = 1;
	}
}

Counter::~Counter() { }
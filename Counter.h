#pragma once

class Counter
{
public:
	void count_up();
	void count_down();
	int count_show(void);
	Counter(int n);
	~Counter();
private:
	int counter;
};
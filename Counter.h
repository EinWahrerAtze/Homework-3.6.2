#pragma once

class Counter
{
public:
	void count_up();
	void count_down();
	int count_show();
	Counter(int n);
private:
	int counter;
};
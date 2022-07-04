#include "Counter.h"
#include <iostream>

void Counter::count_up(void)
{
	++counter;
}

void Counter::count_down(void)
{
	--counter;
}

void Counter::count_show(void)
{
	std::wcout << L"Счётчик = " << counter << std::endl;
}

Counter::Counter(const int n)
{
	if (n != 1)
	{
		std::wcout << L"Начальное значение установлено в " << n << '\n';
		counter = n;
	}
	else
	{
		std::wcout << L"Начальное значение установлено в \"1\"\n";
		counter = 1;
	}
}

Counter::~Counter()
{
	std::wcout << L"Пока!\n";
}
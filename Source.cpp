#include "Counter.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::wcout << L"Хотите указать начальное значение счётчика?\n";
	std::wcout << L"Введите \"да\" или \" нет \": ";

	std::wstring answer;
	getline(std::wcin, answer);
	std::transform(answer.begin(), answer.end(), answer.begin(), ::towlower);

	while (answer != L"да" && answer != L"нет")
	{
		std::wcout << L"Пожалуйста, введите \"да\" или \"нет\": ";
		getline(std::wcin, answer);
	}

	bool check = false;
	answer == L"да" ? check = true : check = false;
	int start_value = 1;

	if (check)
	{
		std::wcout << L"Введите начальное значение: ";

		while (!(std::wcin >> start_value))
		{
			std::wcin.clear();
			while (std::wcin.get() != '\n')
				continue;
			std::wcout << L"Пожалуйста, введите целочисленное значение: ";
		}

		std::wcin.get();
	}

	std::system("cls");
	Counter new_counter = Counter(start_value);

	while (towlower(answer.front()) != L'x' && towlower(answer.front() != L'ч'))
	{
		std::wcout << L"Нажмите '+', '-', '=' или 'X': ";
		getline(std::wcin, answer);

		switch (answer.front())
		{
			case L'+':
				new_counter.count_up();
				break;
			case L'-':
				new_counter.count_down();
				break;
			case L'=':
				new_counter.count_show();
				break;
			case L'ч':
			case L'x':
				break;
			default:
				std::wcout << L"Такого действия нет!\n";
				break;
		}
	}

	return 0;
}
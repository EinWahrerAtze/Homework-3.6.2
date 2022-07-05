#include <iostream>
#include <string>
#include <Windows.h>
#include "Counter.h"

const std::wstring & tolower(std::wstring & const str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		str[i] = towlower(str[i]);
	}

	return str;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::wcout << L"Хотите указать начальное значение счётчика?\n";
	std::wcout << L"Введите \"да\" или \" нет \": ";

	std::wstring answer;
	getline(std::wcin, answer);
	answer = tolower(answer);

	while (answer != L"да" && answer != L"нет")
	{
		std::wcout << L"Пожалуйста, введите \"да\" или \"нет\": ";
		getline(std::wcin, answer);
		answer = tolower(answer);
	}

	bool is_positive = false;
	answer == L"да" ? is_positive = true : is_positive = false;
	
	int start_value = 1;

	if (is_positive)
	{
		std::wcout << L"Введите начальное значение: ";

		while (!(std::wcin >> start_value))
		{
			std::wcin.clear();
			std::wcin.ignore(32767, L'\n');
			while (std::wcin.get() != L'\n')
				continue;
			std::wcout << L"Пожалуйста, введите целочисленное значение: ";
		}

		std::wcin.get();
	}

	std::system("cls");
	std::wcout << L"Начальное значение установлено в " << start_value << L'\n';
	Counter new_counter = Counter(start_value);

	while (towlower(answer.front()) != L'x' && towlower(answer.front() != L'ч'))
	{
		std::wcout << L"Введите команду ('+', '-', '=' или 'X'): ";
		getline(std::wcin, answer);

		switch (answer.front())
		{
			case L'+':
			{
				new_counter.count_up();
				break;
			}
			case L'-':
			{
				new_counter.count_down();
				break;
			}
			case L'=':
			{
				std::wcout << L"Счётчик: " << new_counter.count_show() << std::endl;
				break;
			}
			case L'ч':
			case L'x':
			{
				break;
			}
			default:
			{
				std::wcout << L"Такого действия нет!\n";
				break;
			}
		}
	}

	std::wcout << L"Пока!\n";
	return 0;
}
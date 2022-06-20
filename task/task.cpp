/*
#################### ЗАДАНИЕ ###################
	Разработать класс CDate, включающий следующие
члены:
	• поля day, month, year;
	• константный метод char *DayOfWeek() const;
	• конструктор по умолчанию CDate();
	• конструктор с параметрами CDate(int day, int month,
int year);
	• метод, возвращающий разницу между двумя датами в
днях (перегруженный бинарный оператор «-»);
	• метод изменения даты на заданное количество дней
(перегруженный бинарный оператор «+»);
	• метод вывода даты на экран void PrintDate();
	• перегруженные операции «++», «--», «>», «<», «==»,
«!=».
################################################
		СТАТУС : Не готово.
		ВОЗМОЖНЫЕ ДОРАБОТКИ:
* Разработать swap, для обмена местами дат, при старте программы.
* перегрузить оператор --
		ИЗВЕСТНЫЕ ОШИБКИ:
*
		ПРОТЕСТИРОВАТЬ:
*
		ВОПРОСЫ:
* кгда удалять константный указатель из метода класса DayOfWeek() ? 
		ВИДЕО: 02:35:20(начало дз)
################################################
*/
#include <iostream>
#include "CDate.h"
using std::cout;
using std::boolalpha;
using std::cin;
using std::endl;

int main()
{
	CDate date1{}, date2{}, resultCDate{};

	char action; // Действие с датами.
	char answer{ 0 }; // Хотите повторить ?.
	int days{ 0 };
	bool resultBool{};
	int resultInDays{ 0 };

	do
	{
		switch ('-')
		{
		case '-': // Разница между двумя датами в днях.
			do
			{
				cout << "The first date must be less than the second date."
					<< "\nEnter first date.\n";
				Input(date1);
				if (DateValidationCheck(date1) == false)
					cout << "Try again!" << endl;
			} while (DateValidationCheck(date1) == false);

			do
			{
				cout << "Enter second date.\n";
				Input(date2);
				if (DateValidationCheck(date2) == false)
					cout << "Try again!" << endl;
			} while (DateValidationCheck(date2) == false);

			resultInDays = date1 - date2;
			cout << "\ndate1 - date2 = " << resultInDays << " days.";
			cout << endl;

		case '+': // Изменение даты на заданное количество дней.
			do
			{
				cout << "\nBy how many days to increase the entered dates?\n";
				cin >> days;
				if (days < 0)
					cout << "\nTry again!" << endl;
			} while (days < 0);

			cout << "\ndate1 + days = "; (date1 + days).PrintDate();
			cout << "\ndate2 + days = "; (date2 + days).PrintDate();
			cout << endl;

		case '>':
			cout << "date1 > date2 = " << boolalpha << date1.operator>(date2);
			cout << endl << endl;

		case '<':
			cout << "date1 < date2 = " << boolalpha << date1.operator<(date2);
			cout << endl << endl;

		case '==':
			cout << "date1 == date2 = " << boolalpha << date1.operator==(date2);
			cout << endl << endl;

		case '!=':
			cout << "date1 != date2 = " << boolalpha << date1.operator!=(date2);
			cout << endl << endl;

		case '++':
			cout << "date1++ = ";
			date1.operator++().PrintDate();
			cout << endl;

			cout << "date2++ = ";
			date2.operator++().PrintDate();
			cout << endl << endl;

			/*case '--': // не работает
				cout << "date1-- = ";
				date1.operator--().PrintDate();
				cout << endl << endl;*/

		}
		cout << endl << endl;
		cout << "date1.DayOfWeek() = ";
		date1.PrintDate();
		cout << date1.DayOfWeek();

		cout << endl << endl;
		cout << "date2.DayOfWeek() = ";
		date2.PrintDate();
		cout << date2.DayOfWeek();
		cout << endl << endl;

		cout << endl;
		cout << "Do you want to repeat? ( y (yes) / n (no) )\n";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

}
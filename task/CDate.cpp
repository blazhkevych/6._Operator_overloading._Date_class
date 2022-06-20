#include "CDate.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

enum Months
{
	January = 1,	// Январь, 31 день
	February = 2,	// Февраль, 28 дней (В високосные годы вводится дополнительный день — 29 февраля.)
	March = 3,		// Март, 31 день 
	April = 4,		// Апрель, 30 дней 
	May = 5,		// Май, 31 день 
	June = 6,		// Июнь, 30 дней 
	July = 7,		// Июль, 31 день 
	August = 8,		// Август, 31 день 
	September = 9,	// Сентябрь, 30 дней 
	October = 10,	// Октябрь, 31 день 
	November = 11,	// Ноябрь, 30 дней 
	December = 12	// Декабрь, 31 день 
};

// Метод перегрузки бинарного оператора "-" для "this - object". 
// Возвращает разницу между двумя датами в днях.
int CDate::operator-(const CDate& date) const
{
	return DiffInDaysBetwDates(*(this), date);
}

// Метод перегрузки бинарного оператора "+" для "this + int". 
// Метод изменения даты на заданное количество дней.
CDate CDate::operator+(const int days) const
{
	int daysCOpy = days;
	int day1 = m_day, month1 = m_month, year1 = m_year;

	while (daysCOpy) // Пока даты не равны, вычисляем следующую дату.
	{
		switch (month1)
		{
		case April: // Расчет следующей даты за введенной, для месяцев c 30 днями.
		case June:
		case September:
		case November:
			day1++;
			if (day1 > 30)
			{
				day1 = 1;
				month1++;
				if (month1 > 12)
				{
					month1 = 1;
					year1++;
				}
			}
			break;

		case January: // Расчет следующей даты за введенной, для месяцев c 31 днем.
		case March:
		case May:
		case July:
		case August:
		case October:
		case December:
			day1++;
			if (day1 > 31)
			{
				day1 = 1;
				month1++;
				if (month1 > 12)
				{
					month1 = 1;
					year1++;
				}
			}
			break;

		case February: // Расчет следующей даты за введенной, для февраля (как высокосного так и не високосного).
			day1++;
			if (!(year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0)) && (day1 > 28)) // Не високосный.
			{
				day1 = 1;
				month1++;
				if (month1 > 12)
				{
					month1 = 1;
					year1++;
				}
			}
			else if ((year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0)) && (day1 > 29)) // Високосный.
			{
				day1 = 1;
				month1++;
				if (month1 > 12)
				{
					month1 = 1;
					year1++;
				}
			}
			break;
		}
		daysCOpy--;
		//cout << "Следующая дата: " << day1 << '.' << month1 << '.' << year1 << endl;
	}
	CDate res{ day1,month1,year1 };

	return res;
}

// Метод перегрузки бинарного оператора ">" для "this > object". 
// Метод возвращает true, если "this > object".
bool CDate::operator>(const CDate& date) const
{
	if (m_year > date.m_year)
		return true;
	else
	{
		if (m_month > date.m_month)
			return true;
		else
		{
			if (m_day > date.m_day)
				return true;
			else
				return false;
		}
	}
}

// Метод перегрузки бинарного оператора "<" для "this < object". 
// Метод возвращает true, если "this < object".
bool CDate::operator<(const CDate& date) const
{
	if (m_year < date.m_year)
		return true;
	else
	{
		if (m_month < date.m_month)
			return true;
		else
		{
			if (m_day < date.m_day)
				return true;
			else
				return false;
		}
	}
}

// Метод перегрузки бинарного оператора "==" для "this == object". 
// Метод возвращает true, если "this == object".
bool CDate::operator==(const CDate& date) const
{
	if (m_year == date.m_year && m_month == date.m_month && m_day == date.m_day)
		return true;
	else
		return false;
}

// Метод перегрузки бинарного оператора "!=" для "this != object". 
// Метод возвращает true, если "this != object".
bool CDate::operator!=(const CDate& date) const
{
	if (m_year != date.m_year && m_month != date.m_month && m_day != date.m_day)
		return true;
	else
		return false;
}

// Унарные операторы:
// Метод перегрузки унарного оператора "++" для "this". 
// Метод дает следующую дату.
CDate CDate::operator++() const
{
	return this->operator+(1);
}

// Метод перегрузки унарного оператора "--" для "this". 
// Метод дает предыдущую дату.
CDate CDate::operator--() const
{
	return this->operator+(-1); // не работает. Расписать весь код.
}

// Метод определяет на основании даты день недели. 
const char* CDate::DayOfWeek() const
{
	enum Days_of_the_week
	{
		Monday = 1,		// понедельник
		Tuesday = 2,	// вторник
		Wednesday = 3,	// среда
		Thursday = 4,	// четверг
		Friday = 5,		// пятница
		Saturday = 6,	// суббота
		Sunday = 7		// воскресенье
	};

	int year = m_year, month = m_month, day = m_day;

	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int dow = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7; // ???

	const char* str = new char; // когда удалять этот указатель на строку ????????????

	if (dow == Monday)
		str = { "Monday" };
	else if (dow == Tuesday)
		str = { "Tuesday" };
	else if (dow == Wednesday)
		str = { "Wednesday" };
	else if (dow == Thursday)
		str = { "Thursday" };
	else if (dow == Friday)
		str = { "Friday" };
	else if (dow == Saturday)
		str = { "Saturday" };
	else if (dow == Sunday || dow == 0)
		str = { "Sunday" }; 

	return str;
}

// Метод вывода даты на экран.
void CDate::PrintDate()
{
	cout << this->getDay() << '.' << this->getMonth() << '.' << this->getYear()
		<< endl;
}

// Функция, проверяющая является ли год високосным.
bool IsItALeapYear(CDate date)
{
	int year = date.getYear();
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}

// Функция, проверяющая корректность введенных значений даты.
bool DateValidationCheck(CDate date)
{
	int day = date.getDay();
	int month = date.getMonth();
	int year = date.getYear();
	if (year > 0)
	{
		if (month > 0 && month < 13)
		{
			if (
				((IsItALeapYear(year))
					&& (month == February) && (day == 29)) // Если 29 февраля в високосном году.
				|| ((IsItALeapYear(year))
					&& (month == February) && (day > 0 && day < 29)) // Если 1-28 февраля, високосный год.
				|| (!(IsItALeapYear(year))
					&& (month == February) && (day > 0 && day < 29)) // Если 1-28 февраля, обычный год.
				|| ((month == January
					|| month == March
					|| month == May
					|| month == July
					|| month == August
					|| month == October
					|| month == December) && (day > 0 && day < 32)) // Все месяца, в которых 31 день.
				|| ((month == April
					|| month == June
					|| month == September
					|| month == November) && (day > 0 && day < 31)) // Все месяца, в которых 30 дней.
				)
			{
				return true; // Все введённые значения корректны.
			}
			else
				return false; // Введен не корректный день.
		}
		else
			return false; // Введен не корректный месяц. 
	}
	else
		return false; // Введен не корректный год. 
}

// Функция для ввода даты.
void Input(CDate& date)
{
	cout << "day: ";
	int day;
	cin >> day;
	date.setDay(day);
	cout << "month: ";
	int month;
	cin >> month;
	date.setMonth(month);
	cout << "year: ";
	int year;
	cin >> year;
	date.setYear(year);
}

// Функция, вычисляет разность в днях между этими датами.
int DiffInDaysBetwDates(CDate date1, CDate date2)
{
	int day1 = date1.getDay(), month1 = date1.getMonth(), year1 = date1.getYear(),
		day2 = date2.getDay(), month2 = date2.getMonth(), year2 = date2.getYear();
	int differenceIs{ 0 }; // Счетчик разности в днях между этими датами.

	if (year1 == year2 && month1 == month2 && day1 == day2) // Если даты равны.
	{
		return differenceIs = 0;
	}
	else
	{
		while (!(year1 == year2 && month1 == month2 && day1 == day2)) // Пока даты не равны, вычисляем следующую дату.
		{
			switch (month1)
			{
			case April: // Расчет следующей даты за введенной, для месяцев c 30 днями.
			case June:
			case September:
			case November:
				day1++;
				if (day1 > 30)
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				break;

			case January: // Расчет следующей даты за введенной, для месяцев c 31 днем.
			case March:
			case May:
			case July:
			case August:
			case October:
			case December:
				day1++;
				if (day1 > 31)
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				break;

			case February: // Расчет следующей даты за введенной, для февраля (как высокосного так и не високосного).
				day1++;
				if (!(year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0)) && (day1 > 28)) // Не високосный.
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				else if ((year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0)) && (day1 > 29)) // Високосный.
				{
					day1 = 1;
					month1++;
					if (month1 > 12)
					{
						month1 = 1;
						year1++;
					}
				}
				break;
			}
			//cout << "Следующая дата: " << day1 << '.' << month1 << '.' << year1 << endl;
			differenceIs++;
		}
	}
	return differenceIs;
}
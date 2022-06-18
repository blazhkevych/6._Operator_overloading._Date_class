#include "CDate.h"

// Конструкторы:
// Конструктор по умолчанию (задает начальное значение).
CDate::CDate()
{
	m_day = 1;
	m_month = 1;
	m_year = 1;
}

// Метод определяет на основании даты день недели. // где-то уже делали
const char* CDate::DayOfWeek() const
{
	/*
	
	// Функция определяет день недели.
int Get_DOW(int year, int month, int day)
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int d = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;

	return d ? d : 7;
}
	
	*/

	// возвращать нужно в виде строки char*
	return nullptr;
}

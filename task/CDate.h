#pragma once
class CDate
{
private:
	// Данные - члены(поля) :
	int m_day;
	int m_month;
	int m_year;
public:
	// Конструкторы:
	// Конструктор по умолчанию (задает начальное значение).
	CDate();

	// Конструктор с всеми параметрами.
	CDate(int day, int month, int year)
		:m_day(day), m_month(month), m_year(year) {};


	// Метод определяет на основании даты день недели. 
	const char* DayOfWeek() const;


};


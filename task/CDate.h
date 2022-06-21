#pragma once
class CDate
{
private:
	// Данные - члены(поля) :
	int m_day;
	int m_month;
	int m_year;
public:
	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей).
	int getDay() { return m_day; }
	int getMonth() { return m_month; }
	int getYear() { return m_year; }

	// Модификаторы (позволяют установить значения полей).
	void setDay(int day) { m_day = day; }
	void setMonth(int month) { m_month = month; }
	void setYear(int year) { m_year = year; }

	// Конструкторы:
	// Конструктор по умолчанию (задает начальное значение).
	CDate() :CDate(1, 1, 1) {};

	// Конструктор с всеми параметрами.
	CDate(int day, int month, int year)
		:m_day(day), m_month(month), m_year(year) {};

	// Бинарные операторы:
	// Метод перегрузки бинарного оператора "-" для "this - object". 
	// Возвращает разницу между двумя датами в днях.
	int operator - (const CDate& date) const;

	// Метод перегрузки бинарного оператора "+" для "this + int". 
	// Метод изменения даты на заданное количество дней.
	CDate operator + (const int days) const;

	// Метод перегрузки бинарного оператора ">" для "this > object". 
	// Метод возвращает true, если "this > object".
	bool operator > (const CDate& date) const;

	// Метод перегрузки бинарного оператора "<" для "this < object". 
	// Метод возвращает true, если "this < object".
	bool operator < (const CDate& date) const;

	// Метод перегрузки бинарного оператора "==" для "this == object". 
	// Метод возвращает true, если "this == object".
	bool operator == (const CDate& date) const;

	// Метод перегрузки бинарного оператора "!=" для "this != object". 
	// Метод возвращает true, если "this != object".
	bool operator != (const CDate& date) const;

	// Унарные операторы:
	// Метод перегрузки унарного оператора "++" для "this". 
	// Метод дает следующую дату.
	CDate operator ++ () const;

	// Метод перегрузки унарного оператора "--" для "this". 
	// Метод дает предыдущую дату.
	CDate operator -- () const;

	// Остальные методы.
	// Метод определяет на основании даты день недели. 
	const char* DayOfWeek() const;

	// Метод вывода даты на экран.
	void PrintDate();
};

// Функция для ввода даты.
void Input(CDate& date);

// Функция, проверяющая является ли год високосным.
bool IsItALeapYear(int year);

// Функция, проверяющая корректность введенных значений даты.
bool DateValidationCheck(CDate date);

// Функция для ввода даты.
void Input(CDate& date);

// Функция, вычисляет разность в днях между этими датами.
int DiffInDaysBetwDates(CDate date1, CDate date2);
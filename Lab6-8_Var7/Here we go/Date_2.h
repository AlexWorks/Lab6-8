#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

class Date_2 {
private:
	int year;
	short month;
	short day;
	static int monthsDays[13];
public:
	Date_2(int day = 1, int month = 1, int year = 1980);
	Date_2(const Date_2& p);

	void safeSetDate(int dd = 1, int mm = 1, int yy = 1980);
	void setDate(int dd = 1, int mm = 1, int yy = 1980);
	void setDay(int dd);
	void setMonth(int mm);
	void setYear(int yy);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);
	virtual void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Date_2& p);
};

class ProductionDate : public Date_2 {
public:
	ProductionDate(int day = 1, int month = 1, int year = 1980)
		:Date_2(day, month, year){}
	ProductionDate(const ProductionDate& p): Date_2(p){}

	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const ProductionDate& p);
};

class BookingDate : public Date_2 {
public:
	BookingDate(int day = 1, int month = 1, int year = 1980)
		:Date_2(day, month, year) {}
	BookingDate(const BookingDate& p) : Date_2(p) {}

	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const BookingDate& p);
};

class OperationDate : public Date_2 {
public:
	OperationDate(int day = 1, int month = 1, int year = 1980)
		:Date_2(day, month, year) {}
	OperationDate(const OperationDate& p) : Date_2(p) {}

	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const OperationDate& p);
};


class OperationListDate : public Date_2 {
public:
	OperationListDate(int day = 1, int month = 1, int year = 1980)
		:Date_2(day, month, year) {}
	OperationListDate(const OperationListDate& p) : Date_2(p) {}

	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const OperationListDate& p);
};


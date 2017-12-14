#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

class Date_1 {
private:
	int year;
	short month;
public:
	Date_1(short month = 1, int year = 1980);
	Date_1(const Date_1& p);
	virtual void safeSetMonth(short mm);
	void safeSetYear(int yy);
	void setMonth(short mm);
	void setYear(int yy);
	short getMonth() const;
	int getYear() const;
	
	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);
	friend std::ostream& operator<<(std::ostream& os, const Date_1& p);
};

class FoundationDate : public Date_1 {
public:
	FoundationDate(short mm, int yy):Date_1(mm,yy){}
	FoundationDate(const FoundationDate& p): Date_1(p){}


	friend std::ostream& operator<<(std::ostream& os, const FoundationDate& p);
};

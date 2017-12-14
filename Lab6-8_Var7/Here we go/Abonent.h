#pragma once

#include "Date_2.h"
#include <cstring>
#include <string>

template <class StrType>
class Abonent : public BookingDate {

};

template <>
class Abonent<char*> : public BookingDate {
private:
	char* name;
	char* surname;
public:
	Abonent(int dd = 1, int mm = 1, int yy = 1980, 
		char* name = "Vasia", char* surname = "Pupkin");
	Abonent(const Abonent<char*>& p);
	Abonent(Abonent<char*>&& p);
	~Abonent();

	const Abonent<char*>& operator=(const Abonent& p);
	Abonent<char*>& operator=(Abonent&& p);
	
	const char* getName() const;
	const char* getSurname() const;
	int getBookingDay() const;
	int getBookingMonth() const;
	int getBookingYear() const;

	void setName(char* name);
	void setSafeName(char* name);
	void setSurname(char* surname);
	void setSafeSurname(char* surname);
	void setBookingDate(int dd, int mm, int yy);
	void setSafeBookingDate(int dd, int mm, int yy);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);
	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Abonent<char*>& p);
};

template <>
class Abonent<std::string> : public BookingDate {
private:
	std::string name;
	std::string surname;
public:
	Abonent(int dd = 1, int mm = 1, int yy = 1980,
		std::string name = "Vasia", std::string surname = "Pupkin");
	Abonent(const Abonent<std::string>& p);
	Abonent(Abonent<std::string>&& p);
	~Abonent();

	Abonent<std::string>& operator=(const Abonent<std::string>& p);

	std::string getName() const;
	std::string getSurname() const;
	int getBookingDay() const;
	int getBookingMonth() const;
	int getBookingYear() const;

	void setName(std::string name);
	void setSafeName(std::string name);
	void setSurname(std::string surname);
	void setSafeSurname(std::string surname);
	void setBookingDate(int dd, int mm, int yy);
	void setSafeBookingDate(int dd, int mm, int yy);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);
	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Abonent<std::string>& p);
};
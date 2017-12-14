#pragma once

#include "Date_1.h"
#include <cstring>
#include <string>

template <class StrType>
class Studio : public FoundationDate {};

template<>
class Studio<char*> : public FoundationDate {
private:
	char* studioName;
public:
	Studio(short mm = 1, int yy = 1980, char* name = "Default");
	Studio(const Studio<char*>& p);
	Studio(Studio<char*>&& p);
	~Studio();

	Studio<char*>& operator=(const Studio<char*>& p);
	Studio<char*>& operator=( Studio<char*>&& p);

	const char* getStudioName() const;
	short getFoundationMonth() const;
	int getFoundationYear() const;

	void setStudioName(char* name);
	void safeSetStudioName(char* name);
	void setSafeFoundationMonth(short mm);
	void setSafeFoundationYear(int yy);
	void setFoundationMonth(short mm);
	void setFoundationYear(int yy);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);

	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Studio<char*>& p);

};

template<>
class Studio<std::string> : public FoundationDate {
private:
	std::string studioName;
public:
	Studio(short mm = 1, int yy = 1980, std::string name = "Default");
	Studio(const Studio<std::string>& p);
	~Studio();

	Studio<std::string> operator=(const Studio<std::string>& p);

	std::string getStudioName() const;
	short getFoundationMonth() const;
	int getFoundationYear() const;

	void setStudioName(std::string name);
	void safeSetStudioName(std::string name);
	void setSafeFoundationMonth(short mm);
	void setSafeFoundationYear(int yy);
	void setFoundationMonth(short mm);
	void setFoundationYear(int yy);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);

	friend std::ostream& operator<<(std::ostream& os, const Studio<std::string>& p);
};

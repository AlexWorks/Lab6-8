#pragma once

#include "Date_2.h"
#include "Studio.h"

template <class StrType>
class Disc : public ProductionDate, public Studio<StrType> {
};

template <>
class Disc<char*> : public ProductionDate, public Studio<char*> {
private:
	char* filmName;
	int duration;
public:
	Disc(short mm = 1, int yy = 1980, char* studioName = "Default",
		char* filmName = "Film", int duration = 0,
		int prodDD = 1, int prodMM = 1, int prodYY = 1);
	Disc(const Disc<char*>& p);
	Disc(Disc<char*>&& p);
	~Disc();

	const Disc<char*>& operator=(const Disc<char*>& p);
	Disc<char*>& operator=(Disc<char*>&& p);

	const char* getFilmName() const;
	int getFilmDuration() const;
	int getProductionDay() const;
	int getProductionMonth() const;
	int getProductionYear() const;

	void setFilmName(char* name);
	void setSafeFilmName(char* name);
	void setFilmDuration(int val);
	void setSafeFilmDuration(int val);
	void setSafeProductionDate(int dd, int mm, int yy);
	void setProductionDate(int dd, int mm, int yy);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);

	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Disc<char*>& p);

};

template <>
class Disc<std::string> : public ProductionDate, public Studio<std::string> {
private:
	std::string filmName;
	int duration;
public:
	Disc(short mm = 1, int yy = 1980, std::string studioName = "Default",
		std::string filmName = "Film", int duration = 0, int prodDD = 1, 
		int prodMM = 1, int prodYY = 1980);
	Disc(const Disc<std::string>& p);
	~Disc();

	std::string getFilmName() const;
	int getFilmDuration() const;
	int getProductionDay() const;
	int getProductionMonth() const;
	int getProductionYear() const;

	void setFilmName(std::string name);
	void setSafeFilmName(std::string name);
	void setFilmDuration(int val);
	void setSafeFilmDuration(int val);
	void setSafeProductionDate(int dd, int mm, int yy);
	void setProductionDate(int dd, int mm, int yy);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);
	void printConsole() {
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Disc<std::string>& p);
};
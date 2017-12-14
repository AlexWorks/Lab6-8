#pragma once

#include "Disc.h"
#include "Abonent.h"
#include "OperationType.h"
#include <cstdlib>
#include <ctime>

char* genString(const int len);

unsigned int getUnsigned(unsigned int max, unsigned int min = 0);

template <class StrType>
class Operation;

template <class StrType>
Operation<StrType> createRandomOperation(StrType nothing) {
	StrType studioName = genString(25);
	StrType filmName = genString(40);
	StrType abName = genString(20);
	StrType abSurname = genString(20);


	Operation<StrType> temp(getUnsigned(12, 1), getUnsigned(9999, 1980), studioName, filmName,
		getUnsigned(300, 0), getUnsigned(31, 1), getUnsigned(12, 1), getUnsigned(9999, 1980),
		getUnsigned(31, 1), getUnsigned(12, 1), getUnsigned(9999, 1980), abName,
		abSurname, RETURN, getUnsigned(31, 1), getUnsigned(12, 1), getUnsigned(9999, 1980));

	return temp;

}

template <class StrType>
bool durationCmp(const Operation<StrType>& a, const Operation<StrType>& b);

template <class StrType>
class Operation : public Disc<StrType>, public Abonent<StrType>,
	public OperationType, public OperationDate {
};

template<>
class Operation<char*> : public Disc<char*>, public Abonent<char*>,
	public OperationType, public OperationDate {
public:
	Operation(short mm = 1, int yy = 1, char* studio = "Studio",
		char* film = "Film", int dur = 0, int prodDD = 1, int prodMM = 1,
		int prodYY = 1980, int abDD = 1, int abMM = 1, int abYY = 1980,
		char* abName = "Vasia", char* abSurname = "Pupkin",
		Operation_Type type = RETURN, int opDD = 1,int opMM = 1,
		int opYY = 1980 );
	Operation(const Operation<char*>& p);
	Operation(Operation<char*>&& p);
	~Operation();

	const Operation<char*>& operator=(const Operation<char*>& p);
	bool operator>(const Operation<char*>& p) const;
	bool operator<(const Operation<char*>& p) const;

	int getOperationDay() const;
	int getOperationMonth() const;
	int getOperationYear() const;

	void setOperationDate(int dd, int mm, int yy);
	void setSafeOperationDate(int dd, int mm, int yy);

	friend Operation<char*> createRandomOperation<char*>(char* s);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);

	friend std::ostream& operator<<(std::ostream& os, const Operation<char*>& p);
};

template<>
class Operation<std::string> : public Disc<std::string>, public Abonent<std::string>,
	public OperationType, public OperationDate {
public:
	Operation(short mm = 1, int yy = 1, std::string studio = "Studio",
		std::string film = "Film", int dur = 0, int prodDD = 1, int prodMM = 1,
		int prodYY = 1980, int abDD = 1, int abMM = 1, int abYY = 1980,
		std::string abName = "Vasia", std::string abSurname = "Pupkin",
		Operation_Type type = RETURN, int opDD = 1, int opMM = 1,
		int opYY = 1980);
	Operation(const Operation<std::string>& p);

	const Operation<std::string>& operator=(const Operation<std::string>& p);
	bool operator>(const Operation<std::string>& p) const;
	bool operator<(const Operation<std::string>& p) const;

	int getOperationDay() const;
	int getOperationMonth() const;
	int getOperationYear() const;

	void setOperationDate(int dd, int mm, int yy);
	void setSafeOperationDate(int dd, int mm, int yy);

	friend Operation<std::string> createRandomOperation<std::string>(std::string s);

	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);

	friend std::ostream& operator<<(std::ostream& os, const Operation<std::string>& p);
};
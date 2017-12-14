#include "Operation.h"

Operation<char*>::Operation(short mm, int yy, char* studio,
	char* film, int dur, int prodDD, int prodMM,
	int prodYY, int abDD, int abMM, int abYY,
	char* abName, char* abSurname,
	Operation_Type type, int opDD, int opMM,
	int opYY) : Disc(mm, yy, studio, film, dur,prodDD, prodMM, prodYY),
	Abonent(abDD, abMM, abYY, abName, abSurname), OperationType(type),
	OperationDate(opDD, opMM, opYY){}

Operation<char*>::Operation(const Operation<char*>& p) :
	Disc(p), Abonent(p), OperationType(p), OperationDate(p){}

Operation<char*>::Operation(Operation<char*>&& p) : Disc(std::move(p)), Abonent(std::move(p)), OperationDate(std::move(p)),
OperationType(std::move(p)) {

}

Operation<char*>::~Operation(){}

const Operation<char*>& Operation<char*>::operator=(const Operation<char*>& p) {
	if (this == &p) {
		return *this;
	}

	Disc<char*>::operator=(p);
	Abonent<char*>::operator=(p);
	OperationType::operator=(p);
	OperationDate::operator=(p);

	return *this;
}

bool Operation<char*>::operator>(const Operation<char*>& p) const {
	return strcmp(getFilmName(), p.getFilmName()) > 0;
}

bool Operation<char*>::operator<(const Operation<char*>& p) const {
	return strcmp(getFilmName(), p.getFilmName()) < 0;
}

int Operation<char*>::getOperationDay() const {
	return OperationDate::getDay();
}

int Operation<char*>::getOperationMonth() const {
	return OperationDate::getMonth();
}

int Operation<char*>::getOperationYear() const {
	return OperationDate::getYear();
}

void Operation<char*>::setOperationDate(int dd, int mm, int yy) {
	OperationDate::setDate(dd, mm, yy);
}

void Operation<char*>::setSafeOperationDate(int dd, int mm, int yy) {
	OperationDate::safeSetDate(dd, mm, yy);
}

Operation<std::string>::Operation(short mm, int yy, std::string studio,
	std::string film, int dur, int prodDD, int prodMM,
	int prodYY, int abDD, int abMM, int abYY,
	std::string abName, std::string abSurname,
	Operation_Type type, int opDD, int opMM,
	int opYY) : Disc(mm, yy, studio, film, dur, prodDD, prodMM, prodYY),
	Abonent(abDD, abMM, abYY, abName, abSurname), OperationType(type),
	OperationDate(opDD, opMM, opYY) {}

Operation<std::string>::Operation(const Operation<std::string>& p) :
	Disc(p), Abonent(p), OperationType(p), OperationDate(p) {}


const Operation<std::string>& Operation<std::string>::operator=(const Operation<std::string>& p) {
	if (this == &p) {
		return *this;
	}

	Disc<std::string>::operator=(p);
	Abonent<std::string>::operator=(p);
	OperationType::operator=(p);
	OperationDate::operator=(p);

	return *this;
}


bool Operation<std::string>::operator>(const Operation<std::string>& p) const {
	return getFilmName() > p.getFilmName();
}

bool Operation<std::string>::operator<(const Operation<std::string>& p) const {
	return getFilmName() < p.getFilmName();
}

int Operation<std::string>::getOperationDay() const {
	return OperationDate::getDay();
}

int Operation<std::string>::getOperationMonth() const {
	return OperationDate::getMonth();
}

int Operation<std::string>::getOperationYear() const {
	return OperationDate::getYear();
}

void Operation<std::string>::setOperationDate(int dd, int mm, int yy) {
	OperationDate::setDate(dd, mm, yy);
}

void Operation<std::string>::setSafeOperationDate(int dd, int mm, int yy) {
	OperationDate::safeSetDate(dd, mm, yy);
}

std::ostream& operator<<(std::ostream& os, const Operation<char*>& p) {
	char temp = os.fill();

	os << "Operation data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(40) << "";
	os.put(194);
	os << std::setw(25) << "";
	os.put(194);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(10) << "";
	os.put(194);
	os << std::setw(10) << "";
	os.put(194);
	os << std::setw(10) << "";
	os.put(194);
	os << std::setw(7) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(40) << "Film";
	os.put(179);
	os << std::setw(25) << "Studio";
	os.put(179);
	os << "Dur";
	os.put(179);
	os << std::setw(20) << "Firstname";
	os.put(179);
	os << std::setw(20) << "Surname";
	os.put(179);
	os << std::setw(10) << "PDate";
	os.put(179);
	os << std::setw(10) << "BDate";
	os.put(179);
	os << std::setw(10) << "ODate";
	os.put(179);
	os << std::setw(7) << "FDate";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(40) << "";
	os.put(197);
	os << std::setw(25) << "";
	os.put(197);
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(10) << "";
	os.put(197);
	os << std::setw(10) << "";
	os.put(197);
	os << std::setw(10) << "";
	os.put(197);
	os << std::setw(7) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(40) << p.getFilmName();
	os.put(179);
	os << std::setw(25) << p.getStudioName();
	os.put(179);
	os << std::setw(3) << p.getFilmDuration();
	os.put(179);
	os << std::setw(20) << p.getName();
	os.put(179);
	os << std::setw(20) << p.getSurname();
	os.put(179);
	os.fill('0');
	os << std::setw(2) << p.getProductionDay() << '/'
		<< std::setw(2) << p.getProductionMonth() << '/'
		<< std::setw(4) << p.getProductionYear();
	os.put(179);
	os << std::setw(2) << p.getBookingDay() << '/'
		<< std::setw(2) << p.getBookingMonth() << '/'
		<< std::setw(4) << p.getBookingYear();
	os.put(179);
	os << std::setw(2) << p.getOperationDay() << '/'
		<< std::setw(2) << p.getOperationMonth() << '/'
		<< std::setw(4) << p.getOperationYear();
	os.put(179);
	os << std::setw(2) << p.getFoundationMonth() << '/'
		<< std::setw(4) << p.getFoundationYear();
	os.put(179);
	os.fill(' ');
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(40) << "";
	os.put(193);
	os << std::setw(25) << "";
	os.put(193);
	os << std::setw(3) << "";
	os.put(193);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(7) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

std::ostream& operator<<(std::ostream& os, const Operation<std::string>& p) {
	char temp = os.fill();

	os << "Operation data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(40) << "";
	os.put(194);
	os << std::setw(25) << "";
	os.put(194);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(10) << "";
	os.put(194);
	os << std::setw(10) << "";
	os.put(194);
	os << std::setw(10) << "";
	os.put(194);
	os << std::setw(7) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(40) << "Film";
	os.put(179);
	os << std::setw(25) << "Studio";
	os.put(179);
	os << "Dur";
	os.put(179);
	os << std::setw(20) << "Firstname";
	os.put(179);
	os << std::setw(20) << "Surname";
	os.put(179);
	os << std::setw(10) << "PDate";
	os.put(179);
	os << std::setw(10) << "BDate";
	os.put(179);
	os << std::setw(10) << "ODate";
	os.put(179);
	os << std::setw(7) << "FDate";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(40) << "";
	os.put(197);
	os << std::setw(25) << "";
	os.put(197);
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(10) << "";
	os.put(197);
	os << std::setw(10) << "";
	os.put(197);
	os << std::setw(10) << "";
	os.put(197);
	os << std::setw(7) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(40) << p.getFilmName();
	os.put(179);
	os << std::setw(25) << p.getStudioName();
	os.put(179);
	os << std::setw(3) << p.getFilmDuration();
	os.put(179);
	os << std::setw(20) << p.getName();
	os.put(179);
	os << std::setw(20) << p.getSurname();
	os.put(179);
	os.fill('0');
	os << std::setw(2) << p.getProductionDay() << '/'
		<< std::setw(2) << p.getProductionMonth() << '/'
		<< std::setw(4) << p.getProductionYear();
	os.put(179);
	os << std::setw(2) << p.getBookingDay() << '/'
		<< std::setw(2) << p.getBookingMonth() << '/'
		<< std::setw(4) << p.getBookingYear();
	os.put(179);
	os << std::setw(2) << p.getOperationDay() << '/'
		<< std::setw(2) << p.getOperationMonth() << '/'
		<< std::setw(4) << p.getOperationYear();
	os.put(179);
	os << std::setw(2) << p.getFoundationMonth() << '/'
		<< std::setw(4) << p.getFoundationYear();
	os.put(179);
	os.fill(' ');
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(40) << "";
	os.put(193);
	os << std::setw(25) << "";
	os.put(193);
	os << std::setw(3) << "";
	os.put(193);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(7) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

void Operation<char*>::printText(std::ofstream& os) {
	os.put(' ');
	os << std::setw(40) << getFilmName();
	os.put(' ');
	os << std::setw(25) << getStudioName();
	os.put(' ');
	os << std::setw(3) << getFilmDuration();
	os.put(' ');
	os << std::setw(20) << getName();
	os.put(' ');
	os << std::setw(20) << getSurname();
	os.put(' ');
	os.fill('0');
	os << std::setw(2) << getProductionDay() << '/'
		<< std::setw(2) << getProductionMonth() << '/'
		<< std::setw(4) << getProductionYear();
	os.put(' ');
	os << std::setw(2) << getBookingDay() << '/'
		<< std::setw(2) << getBookingMonth() << '/'
		<< std::setw(4) << getBookingYear();
	os.put(' ');
	os << std::setw(2) << getOperationDay() << '/'
		<< std::setw(2) << getOperationMonth() << '/'
		<< std::setw(4) << getOperationYear();
	os.put(' ');
	os << std::setw(2) << getFoundationMonth() << '/'
		<< std::setw(4) << getFoundationYear();
	os.put(' ');
	os.fill(' ');
	os.put('\n');
}

void Operation<std::string>::printText(std::ofstream& os) {
	os.put(' ');
	os << std::setw(40) << getFilmName();
	os.put(' ');
	os << std::setw(25) << getStudioName();
	os.put(' ');
	os << std::setw(3) << getFilmDuration();
	os.put(' ');
	os << std::setw(20) << getName();
	os.put(' ');
	os << std::setw(20) << getSurname();
	os.put(' ');
	os.fill('0');
	os << std::setw(2) << getProductionDay() << '/'
		<< std::setw(2) << getProductionMonth() << '/'
		<< std::setw(4) << getProductionYear();
	os.put(' ');
	os << std::setw(2) << getBookingDay() << '/'
		<< std::setw(2) << getBookingMonth() << '/'
		<< std::setw(4) << getBookingYear();
	os.put(' ');
	os << std::setw(2) << getOperationDay() << '/'
		<< std::setw(2) << getOperationMonth() << '/'
		<< std::setw(4) << getOperationYear();
	os.put(' ');
	os << std::setw(2) << getFoundationMonth() << '/'
		<< std::setw(4) << getFoundationYear();
	os.put(' ');
	os.fill(' ');
	os.put('\n');
}

void Operation<char*>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}

void Operation<std::string>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}

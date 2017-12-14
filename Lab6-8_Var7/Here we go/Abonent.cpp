#include "Abonent.h"

/*
*	char* implementation
*/

Abonent<char*>::Abonent(int dd, int mm, int yy, char* n, char* s) :
	BookingDate(dd, mm, yy) {
	if (strlen(n) <= 20) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	else {
		name = new char[6];
		strcpy(name, "Vasia");
	}

	if (strlen(s) <= 20) {
		surname = new char[strlen(s) + 1];
		strcpy(surname, s);
	}
	else {
		surname = new char[7];
		strcpy(surname, "Pupkin");
	}
}

Abonent<char*>::Abonent(const Abonent<char*>& p) :BookingDate(p) {
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);

	surname = new char[strlen(p.surname) + 1];
	strcpy(surname, p.surname);
}

Abonent<char*>::Abonent(Abonent<char*>&& p): BookingDate(std::move(p)) {
	name = p.name;
	surname = p.surname;

	p.name = NULL;
	p.surname = NULL;

}

Abonent<char*>::~Abonent() {
	if (name) {
		delete[] name;
	}
	if (surname) {
		delete[] surname;
	}
}

const Abonent<char*>& Abonent<char*>::operator=(const Abonent& p) {
	if (this == &p) {
		return *this;
	}

	BookingDate::operator=(p);

	delete[] name;
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);

	delete[] surname;
	surname = new char[strlen(p.surname) + 1];
	strcpy(surname, p.surname);

	return *this;
}

 Abonent<char*>& Abonent<char*>::operator=( Abonent&& p) {
	 if (this == &p) {
		 return *this;
	 }

	 BookingDate::operator=(std::move(p));
	 if (name) {
		 delete[] name;
	 }
	 name = p.name;
	 p.name = NULL;

	 if (surname) {
		 delete[] surname;
	 }
	 surname = p.name;
	 p.surname = NULL;

	 return *this;
}

const char* Abonent<char*>::getName() const {
	return name;
}

const char* Abonent<char*>::getSurname() const {
	return surname;
}

int Abonent<char*>::getBookingDay() const {
	return BookingDate::getDay();
}

int Abonent<char*>::getBookingMonth() const {
	return BookingDate::getMonth();
}

int Abonent<char*>::getBookingYear() const {
	return BookingDate::getYear();
}

void Abonent<char*>::setName(char* n) {
	delete[] name;

	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Abonent<char*>::setSafeName(char* n) {
	if (strlen(n) <= 20) {
		delete[] name;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
}

void Abonent<char*>::setSurname(char* n) {
	delete[] surname;

	surname = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Abonent<char*>::setSafeSurname(char* n) {
	if (strlen(n) <= 20) {
		delete[] surname;
		surname = new char[strlen(n) + 1];
		strcpy(name, n);
	}
}

void Abonent<char*>::setBookingDate(int dd, int mm, int yy) {
	BookingDate::setDate(dd, mm, yy);
}

void Abonent<char*>::setSafeBookingDate(int dd, int mm, int yy) {
	BookingDate::safeSetDate(dd, mm, yy);
}

std::ostream& operator<<(std::ostream& os, const Abonent<char*>& p) {
	char temp = os.fill();

	os << "Abonent data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(20) << "Firstname";
	os.put(179);
	os << std::setw(20) << "Surname";
	os.put(179);
	os << "Day";
	os.put(179);
	os << "Month";
	os.put(179);
	os << "Year";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(20) << p.getName();
	os.put(179);
	os << std::setw(20) << p.getSurname();
	os.put(179);
	os << std::setw(3) << p.getBookingDay();
	os.put(179);
	os << std::setw(5) << p.getBookingMonth();
	os.put(179);
	os << std::setw(4) << p.getBookingYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(3) << "";
	os.put(193);
	os << std::setw(5) << "";
	os.put(193);
	os << std::setw(4) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

/*
*	string implementation
*/

Abonent<std::string>::Abonent(int dd, int mm, int yy,
	std::string n, std::string s) : BookingDate(dd, mm, yy) {
	if (n.size() <= 20) {
		name = n;
	}
	else {
		name = "Vasia";
	}

	if (s.size() <= 20) {
		surname = s;
	}
	else {
		surname = "Pupkin";
	}
}

Abonent<std::string>::Abonent(const Abonent<std::string>& p) 
	: BookingDate(p) {
	name = p.name;
	surname = p.surname;
}

Abonent<std::string>::~Abonent() {

}

Abonent<std::string>& Abonent<std::string>::operator=(const Abonent<std::string>& p) {
	if (this == &p) {
		return *this;
	}

	BookingDate::operator=(p);

	name = p.name;
	surname = p.surname;

	return *this;
}

std::string Abonent<std::string>::getName() const {
	return name;
}

std::string Abonent<std::string>::getSurname() const {
	return surname;
}

int Abonent<std::string>::getBookingDay() const {
	return BookingDate::getDay();
}

int Abonent<std::string>::getBookingMonth() const {
	return BookingDate::getMonth();
}

int Abonent<std::string>::getBookingYear() const {
	return BookingDate::getYear();
}

void Abonent<std::string>::setName(std::string n) {
	name = n;
}

void Abonent<std::string>::setSafeName(std::string n) {
	if (n.size() <= 20) {
		name = n;
	}
}

void Abonent<std::string>::setSurname(std::string s) {
	surname = s;
}

void Abonent<std::string>::setSafeSurname(std::string s) {
	if (s.size() <= 20) {
		surname = s;
	}
}

void Abonent<std::string>::setBookingDate(int dd, int mm, int yy) {
	BookingDate::setDate(dd, mm, yy);
}

void Abonent<std::string>::setSafeBookingDate(int dd, int mm, int yy) {
	BookingDate::safeSetDate(dd, mm, yy);
}

std::ostream& operator<<(std::ostream& os, const Abonent<std::string>& p) {
	char temp = os.fill();

	os << "Abonent data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(20) << "";
	os.put(194);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(20) << "Firstname";
	os.put(179);
	os << std::setw(20) << "Surname";
	os.put(179);
	os << "Day";
	os.put(179);
	os << "Month";
	os.put(179);
	os << "Year";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(20) << "";
	os.put(197);
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(20) << p.getName();
	os.put(179);
	os << std::setw(20) << p.getSurname();
	os.put(179);
	os << std::setw(3) << p.getBookingDay();
	os.put(179);
	os << std::setw(5) << p.getBookingMonth();
	os.put(179);
	os << std::setw(4) << p.getBookingYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(20) << "";
	os.put(193);
	os << std::setw(3) << "";
	os.put(193);
	os << std::setw(5) << "";
	os.put(193);
	os << std::setw(4) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

void Abonent<char*>::printText(std::ofstream& os) {
	os << std::setw(20) << getName();
	os.put(' ');
	os << std::setw(20) << getSurname();
	os.put(' ');
	os << std::setw(3) << getBookingDay();
	os.put(' ');
	os << std::setw(5) << getBookingMonth();
	os.put(' ');
	os << std::setw(4) << getBookingYear();
	os.put(' ');
	os.put('\n');
}

void Abonent<std::string>::printText(std::ofstream& os) {
	os << std::setw(20) << getName();
	os.put(' ');
	os << std::setw(20) << getSurname();
	os.put(' ');
	os << std::setw(3) << getBookingDay();
	os.put(' ');
	os << std::setw(5) << getBookingMonth();
	os.put(' ');
	os << std::setw(4) << getBookingYear();
	os.put(' ');
	os.put('\n');
}

void Abonent<char*>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}

void Abonent<std::string>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}
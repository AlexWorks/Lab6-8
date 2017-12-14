#include "Disc.h"

/*
*
*	char* implementation
*
*/

Disc<char*>::Disc(short mm, int yy, char* studioName,
	char* fName, int dur, int prodDD, int prodMM,
	int prodYY): 
	Studio(mm, yy, studioName), ProductionDate(prodDD, prodMM, prodYY){
	
	duration = dur;

	if (strlen(fName) <= 40) {
		filmName = new char[strlen(fName) + 1];
		strcpy(filmName, fName);
	}
	else {
		filmName = new char[5];
		strcpy(filmName, "Film");
	}
}

Disc<char*>::Disc(const Disc<char*>& p) : Studio(p), ProductionDate(p) {

	duration = p.duration;

	filmName = new char[strlen(p.filmName) + 1];
	strcpy(filmName, p.filmName);
}

Disc<char*>::Disc(Disc<char*>&& p) : ProductionDate(std::move(p)), Studio(std::move(p)) {
	filmName = p.filmName;
	p.filmName = NULL;

	duration = p.duration;
}

Disc<char*>::~Disc() {
	if (filmName) {
		delete[] filmName;
	}
}

const Disc<char*>& Disc<char*>::operator=(const Disc<char*>& p) {
	if (this == &p) {
		return *this;
	}

	Studio<char*>::operator=(p);
	ProductionDate::operator=(p);

	duration = p.duration;

	delete[] filmName;
	filmName = new char[strlen(p.filmName) + 1];
	strcpy(filmName, p.filmName);

	return *this;
}

Disc<char*>& Disc<char*>::operator=(Disc<char*>&& p) {
	if (this == &p) {
		return *this;
	}

	Studio<char*>::operator=(p);
	ProductionDate::operator=(p);

	duration = p.duration;

	if (filmName) {
		delete[] filmName;
	}
	filmName = p.filmName;
	p.filmName = NULL;

	return *this;
}

const char* Disc<char*>::getFilmName() const {
	return filmName;
}

int Disc<char*>::getFilmDuration() const {
	return duration;
}

int Disc<char*>::getProductionDay() const {
	return ProductionDate::getDay();
}

int Disc<char*>::getProductionMonth() const {
	return ProductionDate::getMonth();
}

int Disc<char*>::getProductionYear() const {
	return ProductionDate::getYear();
}

void Disc<char*>::setFilmName(char* name) {
	delete[] filmName;
	filmName = new char[strlen(name) + 1];
	strcpy(filmName, name);
}

void Disc<char*>::setSafeFilmName(char* name) {
	if (strlen(name) <= 40) {
		delete[] filmName;
		filmName = new char[strlen(name) + 1];
		strcpy(filmName, name);
	}
}

void  Disc<char*>::setFilmDuration(int val) {
	duration = val;
}

void Disc<char*>::setSafeFilmDuration(int val) {
	duration = (val > 0 && val < 1000) ? val : 0;
}

void Disc<char*>::setProductionDate(int dd, int mm, int yy) {
	ProductionDate::setDate(dd, mm, yy);
}

void Disc<char*>::setSafeProductionDate(int dd, int mm, int yy) {
	ProductionDate::safeSetDate(dd, mm, yy);
}

std::ostream& operator<<(std::ostream& os, const Disc<char*>& p) {
	char temp = os.fill();

	os << "Disc data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(40) << "";
	os.put(194);
	os << std::setw(25) << "";
	os.put(194);
	os << std::setw(3) << "";
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
	os << std::setw(10) <<"PDate";
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
	os.fill('0');
	os << std::setw(2) << p.getProductionDay() << '/'
		<< std::setw(2) << p.getProductionMonth() << '/' 
		<< std::setw(4) << p.getProductionYear();
	os.put(179);
	os << std::setw(2) << p.getFoundationMonth() << '/'
		<< std::setw(4) << p.getFoundationYear();
	os.put(179);
	os.put('\n');
	os.fill(' ');
	os.fill(196);
	os.put(192);
	os << std::setw(40) << "";
	os.put(193);
	os << std::setw(25) << "";
	os.put(193);
	os << std::setw(3) << "";
	os.put(193);
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(7) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

void Disc<char*>::printText(std::ofstream& os) {
	os.put(' ');
	os << std::setw(40) << getFilmName();
	os.put(' ');
	os << std::setw(25) << getStudioName();
	os.put(' ');
	os << std::setw(3) << getFilmDuration();
	os.put(' ');
	os.fill('0');
	os << std::setw(2) << getProductionDay() << '/'
		<< std::setw(2) << getProductionMonth() << '/'
		<< std::setw(4) << getProductionYear();
	os.put(' ');
	os << std::setw(2) << getFoundationMonth() << '/'
		<< std::setw(4) << getFoundationYear();
	os.put(' ');
	os.fill(' ');
	os.put('\n');
}

void Disc<char*>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}

/*
*
*	string implementation
*
*/

Disc<std::string>::Disc(short mm, int yy, std::string studioName,
	std::string fName, int dur, int prodDD, int prodMM,
	int prodYY) :Studio(mm, yy, studioName), ProductionDate(prodDD, prodMM, prodYY) {
	duration = dur;
	if (fName.size() <= 40) {
		filmName = fName;
	}
	else {
		filmName = "Film";
	}
}

Disc<std::string>::Disc(const Disc<std::string>& p):Studio(p), ProductionDate(p) {
	filmName = p.filmName;
	duration = p.duration;
}

Disc<std::string>::~Disc() {

}

std::string Disc<std::string>::getFilmName() const {
	return filmName;
}

int Disc<std::string>::getFilmDuration() const {
	return duration;
}

int Disc<std::string>::getProductionDay() const {
	return ProductionDate::getDay();
}

int Disc<std::string>::getProductionMonth() const {
	return ProductionDate::getMonth();
}

int Disc<std::string>::getProductionYear() const {
	return ProductionDate::getYear();
}

void Disc<std::string>::setFilmName(std::string name) {
	filmName = name;
}

void Disc<std::string>::setSafeFilmName(std::string name) {
	if (name.size() <= 45) {
		filmName = name;
	}
}

void  Disc<std::string>::setFilmDuration(int val) {
	duration = val;
}

void Disc<std::string>::setSafeFilmDuration(int val) {
	duration = (val > 0) ? val : 0;
}

void Disc<std::string>::setProductionDate(int dd, int mm, int yy) {
	ProductionDate::setDate(dd, mm, yy);
}

void Disc<std::string>::setSafeProductionDate(int dd, int mm, int yy) {
	ProductionDate::safeSetDate(dd, mm, yy);
}

std::ostream& operator<<(std::ostream& os, const Disc<std::string>& p) {
	char temp = os.fill();

	os << "Disc data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(40) << "";
	os.put(194);
	os << std::setw(25) << "";
	os.put(194);
	os << std::setw(3) << "";
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
	os << std::setw(10) << "PDate";
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
	os.fill('0');
	os << std::setw(2) << p.getProductionDay() << '/'
		<< std::setw(2) << p.getProductionMonth() << '/'
		<< std::setw(4) << p.getProductionYear();
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
	os << std::setw(10) << "";
	os.put(193);
	os << std::setw(7) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

void Disc<std::string>::printText(std::ofstream& os) {
	os.put(' ');
	os << std::setw(40) << getFilmName();
	os.put(' ');
	os << std::setw(25) << getStudioName();
	os.put(' ');
	os << std::setw(3) << getFilmDuration();
	os.put(' ');
	os.fill('0');
	os << std::setw(2) << getProductionDay() << '/'
		<< std::setw(2) << getProductionMonth() << '/'
		<< std::setw(4) << getProductionYear();
	os.put(' ');
	os << std::setw(2) << getFoundationMonth() << '/'
		<< std::setw(4) << getFoundationYear();
	os.put(' ');
	os.put('\n');
}

void Disc<std::string>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}
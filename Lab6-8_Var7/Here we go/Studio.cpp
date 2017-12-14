#include "Studio.h"

/*
*
*	Start char* template implementation	
*
*/

Studio<char*>::Studio(short mm, int yy, char* name) : FoundationDate(mm, yy) {
	if (strlen(name) <= 25) {
		studioName = new char[strlen(name) + 1];
		strcpy(studioName, name);
	}
	else {
		studioName = new char[8];
		strcpy(studioName, "Default");
	}
}

Studio<char*>::Studio(const Studio<char*>& p):FoundationDate(p) {
	studioName = new char[strlen(p.studioName) + 1];
	strcpy(studioName, p.studioName);
}

Studio<char*>::Studio(Studio<char*>&& p) : FoundationDate(std::move(p)) {
	studioName = p.studioName;
	p.studioName = NULL;
}

Studio<char*>::~Studio() {
	if (studioName) {
		delete[] studioName;
	}
}

Studio<char*>& Studio<char*>::operator=(const Studio<char*>& p) {
	if (this == &p) {
		return *this;
	}

	FoundationDate::operator=(p);
	
	delete[] studioName;
	studioName = new char[strlen(p.studioName) + 1];
	strcpy(studioName, p.studioName);

	return *this;
}

Studio<char*>& Studio<char*>::operator=(Studio<char*>&& p) {
	if (this == &p) {
		return *this;
	}

	FoundationDate::operator=(p);
	if (studioName) {
		delete[] studioName;
	}
	studioName = p.studioName;
	p.studioName = NULL;

	return *this;
}

const char* Studio<char*>::getStudioName() const {
	return studioName;
}

short Studio<char*>::getFoundationMonth() const {
	return FoundationDate::getMonth();
}

int Studio<char*>::getFoundationYear() const {
	return FoundationDate::getYear();
}

void Studio<char*>::setStudioName(char* name) {
	delete studioName;
	studioName = new char[strlen(name) + 1];
	strcpy(studioName, name);
}

void Studio<char*>::safeSetStudioName(char* name) {
	if (strlen(name) <= 25) {
		studioName = new char[strlen(name) + 1];
		strcpy(studioName, name);
	}
}

void Studio<char*>::setSafeFoundationMonth(short mm) {
	FoundationDate::safeSetMonth(mm);
}

void Studio<char*>::setSafeFoundationYear(int yy) {
	FoundationDate::safeSetYear(yy);
}

void Studio<char*>::setFoundationMonth(short mm) {
	FoundationDate::setMonth(mm);
}

void Studio<char*>::setFoundationYear(int yy) {
	FoundationDate::setYear(yy);
}

std::ostream& operator<<(std::ostream& os, const Studio<char*>& p) {
	char temp = os.fill();

	os << "Studio data:" << std::endl;

	os.fill(196);
	os.put(218); 
	os << std::setw(25) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(25) << "StudioName";
	os.put(179);
	os << "Month";
	os.put(179);
	os << "Year";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(25) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(25) << p.getStudioName();
	os.put(179);
	os << std::setw(5) << p.getFoundationMonth();
	os.put(179);
	os << std::setw(4) << p.getFoundationYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(25) << "";
	os.put(193);
	os << std::setw(5) << "";
	os.put(193);
	os << std::setw(4) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

void Studio<char*>::printText(std::ofstream& os) {
	os << std::setw(25) << getStudioName();
	os.put(' ');
	os << std::setw(5) << getFoundationMonth();
	os.put(' ');
	os << std::setw(4) << getFoundationYear();
	os.put(' ');
	os.put('\n');
}

void Studio<char*>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}

/*
*
*	End char* template implementation
*
*/

/*
*
*	Start string template implementation
*
*/

Studio<std::string>::Studio(short mm, int yy, std::string name):FoundationDate(mm, yy) {
	if (name.size() <= 25) {
		studioName = name;
	}
	else {
		studioName = "Default";
	}
}

Studio<std::string>::Studio(const Studio<std::string>& p):FoundationDate(p) {
	studioName = p.studioName;
}

Studio<std::string>::~Studio() {

}

Studio<std::string> Studio<std::string>::operator=(const Studio<std::string>& p) {
	if (this == &p) {
		return *this;
	}

	studioName = p.studioName;
	setFoundationMonth(p.getFoundationMonth());
	setFoundationYear(p.getFoundationYear());

	return *this;
}

std::string Studio<std::string>::getStudioName() const {
	return studioName;
}

short Studio<std::string>::getFoundationMonth() const {
	return FoundationDate::getMonth();
}

int Studio<std::string>::getFoundationYear() const {
	return FoundationDate::getYear();
}

void Studio<std::string>::setStudioName(std::string name) {
	studioName = name;
}

void Studio<std::string>::safeSetStudioName(std::string name) {
	if (name.size() <= 25) {
		studioName = name;
	}
}

void Studio<std::string>::setSafeFoundationMonth(short mm) {
	FoundationDate::safeSetMonth(mm);
}

void Studio<std::string>::setSafeFoundationYear(int yy) {
	FoundationDate::safeSetYear(yy);
}

void Studio<std::string>::setFoundationMonth(short mm) {
	FoundationDate::setMonth(mm);
}

void Studio<std::string>::setFoundationYear(int yy) {
	FoundationDate::setYear(yy);
}

std::ostream& operator<<(std::ostream& os, const Studio<std::string>& p) {
	char temp = os.fill();

	os << "Studio data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(25) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(25) << "StudioName";
	os.put(179);
	os << "Month";
	os.put(179);
	os << "Year";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(25) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(25) << p.getStudioName();
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(25) << "";
	os.put(193);
	os << std::setw(5) << "";
	os.put(193);
	os << std::setw(4) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

void Studio<std::string>::printText(std::ofstream& os) {
	os << std::setw(25) << getStudioName();
	os.put(' ');
	os << std::setw(5) << getFoundationMonth();
	os.put(' ');
	os << std::setw(4) << getFoundationYear();
	os.put(' ');
	os.put('\n');
}

void Studio<std::string>::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}


/*
*
*	End string template implementation
*
*/
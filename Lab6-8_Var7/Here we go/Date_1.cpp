#include "Date_1.h"

Date_1::Date_1(short mm, int yy) {
	month = (mm > 0 && mm < 13) ? mm : 1;
	year = (yy > 1979 && yy < 10000) ? yy : 1980;
}

Date_1::Date_1(const Date_1& p) {
	month = p.month;
	year = p.year;
}

void Date_1::safeSetMonth(short mm) {
	month = (mm > 0 && mm < 13) ? mm : month;
}

void Date_1::safeSetYear(int yy) {
	year = (yy >= 1980 && yy <= 9999) ? yy : year;
}

void Date_1::setMonth(short mm) {
	month = mm;
}

void Date_1::setYear(int yy) {
	year = yy;
}

short Date_1::getMonth() const {
	return month;
}

int Date_1::getYear() const {
	return year;
}

std::ostream& operator<<(std::ostream& os, const Date_1& p) {

	char temp = os.fill();

	os << "Date_1 data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << "Month";
	os.put(179);
	os << "Year";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(5) << "";
	os.put(193);
	os << std::setw(4) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
 }


void Date_1::printText(std::ofstream& os) {
	char temp = os.fill();

	os.fill(' ');
	os.put(' ');
	os << std::setw(2) << getMonth();
	os.put(' ');
	os << std::setw(4) << getYear();
	os.put('\n');
}

void Date_1::printBinary(std::ofstream& os) {
		os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}

std::ostream& operator<<(std::ostream& os, const FoundationDate& p) {
	char temp = os.fill();

	os << "FoundationDate data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << "Month";
	os.put(179);
	os << "Year";
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(195);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
	os << std::setw(5) << "";
	os.put(193);
	os << std::setw(4) << "";
	os.put(217);
	os.put('\n');


	os.fill(temp);
	return os;
}

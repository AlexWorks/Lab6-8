#include "Date_2.h"

int Date_2::monthsDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

Date_2::Date_2(int day, int month, int year) {
	safeSetDate(day, month, year);
}

Date_2::Date_2(const Date_2& p) {
	day = p.day;
	month = p.month;
	year = p.year;
}

void Date_2::safeSetDate(int dd, int mm, int yy) {
	month = (mm >= 1 && mm <= 12) ? mm : 1;
	year = (yy >= 1980 && yy <= 3000) ? yy : 1980;

	if (month == 2 && year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) {
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	}
	else {
		day = (dd >= 1 && dd <= monthsDays[month]) ? dd : 1;
	}
}

void Date_2::setDate(int dd, int mm, int yy) {
	day = dd;
	month = mm;
	year = yy;
}

void Date_2::setDay(int dd) {
	safeSetDate(dd, month, year);
}

void Date_2::setMonth(int mm) {
	safeSetDate(day, mm, year);
}

void Date_2::setYear(int yy) {
	safeSetDate(day, month, yy);
}

int Date_2::getDay() const {
	return day;
}

int Date_2::getMonth() const {
	return month;
}

int Date_2::getYear() const {
	return year;
}

std::ostream& operator<<(std::ostream& os, const Date_2& p) {
	char temp = os.fill();

	os << "Date_1 data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
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
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(3) << p.getDay();
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
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

std::ostream& operator<<(std::ostream& os, const ProductionDate& p) {
	char temp = os.fill();

	os << "ProductionDate data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
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
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(3) << p.getDay();
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
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

std::ostream& operator<<(std::ostream& os, const BookingDate& p) {
	char temp = os.fill();

	os << "BookingDate data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
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
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(3) << p.getDay();
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
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

std::ostream& operator<<(std::ostream& os, const OperationDate& p) {
	char temp = os.fill();

	os << "OperationDate data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
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
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(3) << p.getDay();
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
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

std::ostream& operator<<(std::ostream& os, const OperationListDate& p) {
	char temp = os.fill();

	os << "OperationListDate data:" << std::endl;

	os.fill(196);
	os.put(218);
	os << std::setw(3) << "";
	os.put(194);
	os << std::setw(5) << "";
	os.put(194);
	os << std::setw(4) << "";
	os.put(191);
	os.put('\n');
	os.fill(' ');
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
	os << std::setw(3) << "";
	os.put(197);
	os << std::setw(5) << "";
	os.put(197);
	os << std::setw(4) << "";
	os.put(180);
	os.put('\n');
	os.fill(' ');
	os.put(179);
	os << std::setw(3) << p.getDay();
	os.put(179);
	os << std::setw(5) << p.getMonth();
	os.put(179);
	os << std::setw(4) << p.getYear();
	os.put(179);
	os.put('\n');
	os.fill(196);
	os.put(192);
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

void Date_2::printText(std::ofstream& os) {
	os << std::setw(3) << getDay();
	os.put(' ');
	os << std::setw(5) << getMonth();
	os.put(' ');
	os << std::setw(4) << getYear();
	os.put(' ');
	os.put('\n');
}

void Date_2::printBinary(std::ofstream& os) {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
}
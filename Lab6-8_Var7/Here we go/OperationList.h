#pragma once

#include "Operation.h"
#include <cassert>


template <class T, class StrType>
class OperationList;

template <class T, class StrType>
int getAverageDuration(const OperationList<T, StrType>& list);

template <class T, class StrType>
std::ostream& operator<< (std::ostream& os, const OperationList<T, StrType>& list);

template <class T, class StrType>
class OperationList : public OperationListDate {
private:
	T size;
	T quantity;
	Operation<StrType>* pointer;
public:
	OperationList(T size = 10, int dd = 1, int mm = 1,int yy = 1980);
	OperationList(const OperationList<T, StrType>& p);
	~OperationList();

	const OperationList<T, StrType>& operator=(const OperationList<T, StrType>& p);
	const Operation<StrType> operator[](T index) const;

	T getSize() const;
	T getQuantity() const;
	int getOperationListDay() const;
	int getOperationListMonth() const;
	int getOperationListYear() const;

	void setOperationListDate(int dd, int mm, int yy);
	void setSafeOperationListDate(int dd, int mm, int yy);

	void insert(const Operation<StrType>& item);
	void fill();

	void sortByName();
	void sortByDuration();
	void sortByNameSw();
	void sortByDurationSw();

	friend int getAverageDuration<>(const OperationList<T, StrType>& list);
	friend std::ostream& operator<<<>(std::ostream& os, const OperationList<T, StrType>& list);
};

template <class T, class StrType>
OperationList<T, StrType>::OperationList(T s, int dd, int mm, int yy) :
	OperationListDate(dd, mm, yy) {
	size = s;
	quantity = 0;
	pointer = new Operation<StrType>[s];
}

template <class T, class StrType>
OperationList<T, StrType>::OperationList(const OperationList& p) :
	OperationListDate(p) {
	size = p.size;
	quantity = p.quantity;
	pointer = new Operation<StrType>[size];

	for (T i = 0; i < quantity; i++) {
		pointer[i] = p[i];
	}
}

template <class T, class StrType>
OperationList<T, StrType>::~OperationList() {
	delete[] pointer;
}

template <class T, class StrType>
const OperationList<T, StrType>& OperationList<T, StrType>::operator=(const OperationList<T, StrType>& p) {
	if (this == &p) {
		return *this;
	}

	delete[] pointer;

	size = p.size;
	quantity = p.quantity;
	pointer = new Operation[size];

	for (T i = 0; i < quantity; i++) {
		pointer[i] = p[i];
	}

	return *this;
}

template <class T, class StrType>
const Operation<StrType> OperationList<T, StrType>::operator[](T index) const {
	assert(index >= 0 && index < quantity);

	return pointer[index];
}

template <class T, class StrType>
T OperationList<T, StrType>::getSize() const {
	return size;
}

template <class T, class StrType>
T OperationList<T, StrType>::getQuantity() const {
	return quantity;
}


template <class T, class StrType>
int OperationList<T, StrType>::getOperationListDay() const {
	return OperationListDate::getDay();
}

template <class T, class StrType>
int OperationList<T, StrType>::getOperationListMonth() const {
	return OperationListDate::getMonth();
}

template <class T, class StrType>
int OperationList<T, StrType>::getOperationListYear() const {
	return OperationListDate::getYear();
}

template <class T, class StrType>
void OperationList<T, StrType>::setOperationListDate(int dd, int mm, int yy) {
	OperationListDate::setDate(dd, mm, yy);
}

template <class T, class StrType>
void OperationList<T, StrType>::setSafeOperationListDate(int dd, int mm, int yy) {
	OperationListDate::setSafeDate(dd, mm, yy);
}

template <class T, class StrType>
void OperationList<T, StrType>::insert(const Operation<StrType>& item) {
	assert(quantity < size);
	pointer[quantity++] = item;
}

template <class T, class StrType>
void OperationList<T, StrType>::fill() {

	StrType temp = "1";

	for (T i = quantity; i < size; i++) {
		insert(createRandomOperation(temp));
	}
}

template <class T, class StrType>
void OperationList<T, StrType>::sortByName() {
	/* Selection Sort */
	for (T i = 0; i < quantity - 1; i++) {
		for (T j = i + 1; j < quantity; j++) {
			if (pointer[i] > pointer[j]) {
				Operation<StrType> temp = pointer[i];
				pointer[i] = pointer[j];
				pointer[j] = temp;
			}
		}
	}
}

template <class T, class StrType>
void OperationList<T, StrType>::sortByDuration() {
	/* Selection Sort */
	for (T i = 0; i < quantity - 1; i++) {
		for (T j = i + 1; j < quantity; j++) {
			if (pointer[i].getFilmDuration() > pointer[j].getFilmDuration()) {
				Operation<StrType> temp = pointer[i];
				pointer[i] = pointer[j];
				pointer[j] = temp;
			}
		}
	}
}

template <class T, class StrType>
void OperationList<T, StrType>::sortByNameSw() {
	/* Selection Sort */
	for (T i = 0; i < quantity - 1; i++) {
		for (T j = i + 1; j < quantity; j++) {
			if (pointer[i] > pointer[j]) {
				std::swap(pointer[i], pointer[j]);
			}
		}
	}
}

template <class T, class StrType>
void OperationList<T, StrType>::sortByDurationSw() {
	/* Selection Sort */
	for (T i = 0; i < quantity - 1; i++) {
		for (T j = i + 1; j < quantity; j++) {
			if (pointer[i].getFilmDuration() > pointer[j].getFilmDuration()) {
				std::swap(pointer[i], pointer[j]);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////

template <class T, class StrType>
int getAverageDuration(const OperationList<T, StrType>& list) {
	float sum = 0;

	for (T i = 0; i < list.quantity; i++) {
		sum = sum + (list[i]).getFilmDuration();
	}

	return sum / list.quantity;
}

template <class T, class StrType>
std::ostream& operator<< (std::ostream& os, const OperationList<T, StrType>& list) {
	char temp = os.fill();

	os << "OperationList data:" << std::endl;

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
	for (T i = 0; i < list.quantity; i++) {
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
		os << std::setw(40) << list[i].getFilmName();
		os.put(179);
		os << std::setw(25) << list[i].getStudioName();
		os.put(179);
		os << std::setw(3) << list[i].getFilmDuration();
		os.put(179);
		os << std::setw(20) << list[i].getName();
		os.put(179);
		os << std::setw(20) << list[i].getSurname();
		os.put(179);
		os.fill('0');
		os << std::setw(2) << list[i].getProductionDay() << '/'
			<< std::setw(2) << list[i].getProductionMonth() << '/'
			<< std::setw(4) << list[i].getProductionYear();
		os.put(179);
		os << std::setw(2) << list[i].getBookingDay() << '/'
			<< std::setw(2) << list[i].getBookingMonth() << '/'
			<< std::setw(4) << list[i].getBookingYear();
		os.put(179);
		os << std::setw(2) << list[i].getOperationDay() << '/'
			<< std::setw(2) << list[i].getOperationMonth() << '/'
			<< std::setw(4) << list[i].getOperationYear();
		os.put(179);
		os << std::setw(2) << list[i].getFoundationMonth() << '/'
			<< std::setw(4) << list[i].getFoundationYear();
		os.put(179);
		os.fill(' ');
		os.put('\n');
	}
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

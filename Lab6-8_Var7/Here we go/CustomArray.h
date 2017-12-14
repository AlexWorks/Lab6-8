#pragma once

#include <typeinfo>
#include <iostream>
#include <cassert>

template <class Type>
class CustomArray {
private:
	Type* pointer;
	int size;
	int quantity;
public:
	CustomArray(int size = 10);
	CustomArray(const CustomArray<Type>& p);
	~CustomArray();

	const CustomArray<Type>& operator=(const CustomArray<Type>& p);
	Type& operator[] (int index) const;

	int getSize() const;
	int getQuantity() const;

	void insert(const Type& item);
	void printText(std::ofstream& descr);
	void printBinary(std::ofstream& descr);
};
 
template <class Type>
CustomArray<Type>::CustomArray(int s) {
	if (s < 1) { s = 10; }
	pointer = new Type[s];
	quantity = 0;
	size = s;
}

template <class Type>
CustomArray<Type>::CustomArray(const CustomArray<Type>& p) {
	size = p.size;
	quantity = p.quantity;

	pointer = new Type[size];

	for (int i = 0; i < quantity; i++) {
		pointer[i] = p.pointer[i];
	}
}

template <class Type>
CustomArray<Type>::~CustomArray() {
	delete[] pointer;
}

template <class Type>
const CustomArray<Type>& CustomArray<Type>::operator=(const CustomArray<Type>& p) {
	if (this == &p) {
		return *this;
	}

	delete pointer;

	size = p.size;
	quantity = p.quantity;

	pointer = new Type[size];

	for (int i = 0; i < quantity; i++) {
		pointer[i] = p.pointer[i];
	}

	return *this;
}

template <class Type>
Type& CustomArray<Type>::operator[](int index) const {
	assert(index >= 0 && index < quantity);

	return pointer[index];
}

template <class Type>
int CustomArray<Type>::getSize() const {
	return size;
}

template <class Type>
int CustomArray<Type>::getQuantity() const {
	return quantity;
}

template <class Type>
void CustomArray<Type>::insert(const Type& p) {
	assert(quantity < size);
	pointer[quantity++] = p;
}

template <class Type>
void CustomArray<Type>::printText(std::ofstream& descr) {


	for (int i = 0; i < quantity; i++) {
		pointer[i].printText(descr);
	}
}

template <class Type>
void CustomArray<Type>::printBinary(std::ofstream& descr) {


	for (int i = 0; i < quantity; i++) {
		pointer[i].printBinary(descr);
	}
}
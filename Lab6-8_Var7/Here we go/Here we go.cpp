#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Studio.h"
#include "OperationList.h"
#include "CustomArray.h"
#include "FileError.h"
#include <vector>
#include <algorithm>

int getTypeSizeFromId(const std::type_info& p);

bool durationCmp(const Operation<char*>& a, const Operation<char*>& b);


int main()
{
	srand(time(NULL));

	Operation<std::string> test_2(1, 2017);
	Operation<std::string> test( 5, 2015, "Sania", "Goreliy");

	OperationList<int, std::string> dimas(2);
	dimas.insert(test_2);
	dimas.insert(test);

	std::cout << dimas << std::endl;
	
	std::ofstream file;
	file.open("test.bin", std::ios::binary);
	if(file.is_open())
	{
		CustomArray<Operation<std::string>> arr(2);

		arr.insert(test);
		arr.insert(test_2);
		arr.printBinary(file);
		file.close();
	}
	else std::cout << "Unable to open file\n\n";

	file.open("test.txt");
	if (file.is_open())
	{
		CustomArray<Operation<std::string>> arr(2);

		arr.insert(test);
		arr.insert(test_2);
		arr.printText(file);
		file.close();
	}

	else std::cout << "Unable to open file\n\n";

	/* <char*> and <std::string> sort time comparasion*/

	OperationList<unsigned int, std::string> listS(200, 2, 3, 2017);
	OperationList<unsigned int, char*> listC(200, 2, 3, 2017);
	listC.fill();
	listS.fill();

	long start = GetTickCount();
	listC.sortByName();
	long end = GetTickCount();

	std::cout << "Size of Operation<char*>: " << sizeof(Operation<char*>) << std::endl;
	std::cout << "Average duration: " << getAverageDuration(listC) << std::endl;
	std::cout << "Operation<char*> sort time: " << end - start << std::endl << std::endl;

	start = GetTickCount();
	listS.sortByName();
	end = GetTickCount();

	std::cout << "Size of Operation<std::string>: " << sizeof(Operation<std::string>) << std::endl;
	std::cout << "Average duration: " <<  getAverageDuration(listS) << std::endl;
	std::cout << "Operation<std::string> sort time: " << end - start << "\n" << std::endl;

	OperationList<unsigned int, std::string> copy = listS;

	//std::cout << listC << listS << std::endl;

	/* Sort speed comparasion*/

	start = GetTickCount();
	listC.sortByDuration();
	end = GetTickCount();

	std::cout << "Operation<char*> selection sort by int field time: " << end - start  << "\n" << std::endl;

	start = GetTickCount();
	listC.sortByName();
	end = GetTickCount();

	std::cout << "Operation<char*> selection sort by char* field time: " << end - start << "\n" << std::endl;

	start = GetTickCount();
	listC.sortByDuration();
	end = GetTickCount();

	std::cout << "Operation<char*> selection sort by int field time using move operations: " << end - start << "\n" << std::endl;

	start = GetTickCount();
	listC.sortByName();
	end = GetTickCount();

	std::cout << "Operation<char*> selection sort by char* field time using move operations: " << end - start << "\n" << std::endl;

	std::vector<Operation<char*>> vector;
	int quantity = listC.getQuantity();
	for (int i = 0; i < quantity; i++) {
		vector.push_back(listC[i]);
	}

	start = GetTickCount();
	std::sort(vector.begin(), vector.end(), durationCmp);
	end = GetTickCount();

	std::cout << "Operation<char*> sort() by int field time: " << end - start << "\n" << std::endl;

	start = GetTickCount();
	std::sort(vector.begin(), vector.end());
	end = GetTickCount();

	std::cout << "Operation<char*> sort() by char* field time: " << end - start << "\n" << std::endl;

	/*for (std::vector<Operation<char*>>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it;*/

	/*///////////////////////////////////////////////////////////////////*/

	/* Working w/ typeid() */

	try {

		Date_2 d2(12, 2012);
		OperationDate opDate(1, 3, 2018);
		Abonent<std::string> abString(6, 4, 1999, "Leha", "String");
		Disc<std::string> discString(1, 1, "Nazarchuk", "2 Stringa", 20, 2, 4, 1985);
		Abonent<char*> abChar(2, 2, 2005,"Tolstii", "2 chara");
		Disc<char*> discChar(1, 1, "Nazarchuk", "2 chara", 20, 2, 4, 1985);

		std::ofstream outfile;
		outfile.open("test.dat", std::ios::binary);

		Date_2** arr = new Date_2*[6];
		if (outfile.is_open())
		{
			arr[0] = &d2;
			arr[1] = &opDate;
			arr[2] = &abString;
			arr[3] = &discString;
			arr[4] = new Abonent<char*>(abChar);
			arr[5] = new Disc<char*>(discChar);
			int temp;
			for (int i = 0; i < 6; i++) {
				temp = getTypeSizeFromId(typeid(*(arr[i])));
				std::cout << temp << " " << typeid(*arr[i]).name() << std::endl;
				outfile.write(reinterpret_cast<const char*>(arr[i]), temp);
			}

			outfile.close();
		}
		else {
			FileError err("File couldn't be opened");
			throw err;
		}

		std::ifstream infile;
		infile.open("test.dat", std::ios::binary);
		if (infile.is_open())
		{
			Date_2** arrN = new Date_2*[2];
			arrN[0] = new Date_2;
			arrN[1] = new OperationDate;
			arrN[2] = new Abonent<std::string>;
			arrN[3] = new Disc<std::string>;
			arrN[4] = new Abonent<char*>;
			arrN[5] = new Disc<char*>;
			int temp;
			for (int i = 0; i < 6; i++) {
				temp = getTypeSizeFromId(typeid(*(arrN[i])));
				infile.read(reinterpret_cast<char*>(arrN[i]), temp);
				arrN[i]->printConsole();
				arrN[i] = arr[i];
			}

			infile.close();
		}
		else {
			FileError err("File couldn't be opened");
			throw err;
		}

		///////////////////////////////////////////

	}
	catch (FileError& err) {
		std::cout << err.what() << std::endl;
	}
	
	system("pause>nul");

    return 0;
}

bool durationCmp(const Operation<char*>& a, const Operation<char*>& b) {
	return a.getFilmDuration() < b.getFilmDuration();
}

int getTypeSizeFromId(const std::type_info& p) {
	
	if (p == typeid(Date_2) || p == typeid(ProductionDate) || p == typeid(BookingDate)
		|| p == typeid(OperationDate) || p == typeid(OperationListDate)) {
		return sizeof(Date_2);
	}

	if (p == typeid(Abonent<char*>)) {
		return sizeof(Abonent<char*>);
	}

	if (p == typeid(Abonent<std::string>)) {
		return sizeof(Abonent<std::string>);
	}

	if (p == typeid(Disc<char*>)) {
		return sizeof(Disc<char*>);
	}

	if (p == typeid(Disc<std::string>)) {
		return sizeof(Disc<std::string>);
	}

	
}

char* genString(const int len) {

	int size = rand() % len + 1;
	char* s = new char[size + 1];

	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < size; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[size] = '\0';
	return s;
}

unsigned int getUnsigned(unsigned int max, unsigned int min) {
	return rand() % (max - min + 1) + min;
}
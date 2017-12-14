#pragma once

#include <iostream>.
#include <exception>
#include <string>

class FileError : public std::exception {
private:
	std::string message;
public:
	FileError(std::string mes) : std::exception(), message(mes){}
	virtual const char* what() const {
		return message.c_str();
	}
};

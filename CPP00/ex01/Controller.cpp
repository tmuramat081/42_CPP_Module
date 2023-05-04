#include <iostream>
#include <sstream>
#include "Controller.hpp"
#include "PhoneBook.hpp"

Controller::Controller() {
	this->_state = 0;
}

Controller::~Controller() {};

Controller::PhoneBookResponse Controller::route(std::string line)
{
	std::transform(line.begin(), line.end(), line.begin(), ::toupper);
	if (this->_state == MODE_CREATE)
	{
		return this->createContactController(line);
	}
	else if (this->_state == MODE_FIND)
	{
		return this->findContactController(line);
	}
	if (line == "ADD")
	{
		std::cout << "ADD: save a new contact." << std::endl;
		this->_state = MODE_CREATE;
		return SUCCESS;

	}
	else if (line == "SEARCH")
	{
		std::cout << "SEARCH: display a specific contact." << std::endl;
		this->_state = MODE_FIND;
		return SUCCESS;
	}
	else if (line == "EXIT")
	{
		std::cout << "EXIT: Have a great day!" << std::endl;
		return RESPONSE_EOF;
	}
	else
	{
		std::cout << "Invalid command" << std::endl;
		return ERROR;
	}
}

#include <stdio.h>

Controller::PhoneBookResponse Controller::createContactController(std::string line)
{
	
	return SUCCESS;
}

Controller::PhoneBookResponse Controller::findContactController(std::string line)
{
	std::istringstream ss;
	int index;

	index = ::atoi(line.c_str());
	book.findContact(index);
	return SUCCESS;
}

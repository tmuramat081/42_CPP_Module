#include <iostream>
#include <sstream>
#include "Controller.hpp"
#include "PhoneBook.hpp"
#include "View/PhoneBookView.hpp"

Controller::Controller() {
	this->_state = 0;
}

Controller::~Controller() {};

void Controller::routeController()
{
	std::string line;
	while (42)
	{
		PhoneBookView.displayInformation();
		std::getline(std::cin, line);
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		if (line == "SEARCH")
		{
			this->findContact();
		}
		else if (line == "ADD")
		{
			this->createContact();
		}
		else if (line == "EXIT")
		{
			return ;
		}
	}
}

void Controller::findContactController(void)
{
	int index;

	
	std::cout << "Enter any index number" << std::endl;
	while (42)
	{
		std::cin >> index;

	}
}

void Controller::createContactController(void)
{
	std::string line;
	else
	{
		std::cout << "Invalid command" << std::endl;
		return ERROR;
	}
}


Controller::PhoneBookResponse Controller::createContactController(std::string line)
{
	std::string word[5];
	for (int i = 0; i < 5; i++)
	{
		std::cin >> word[i];
	}
	Contact createContactDto(
	book.createContact(createContactDto);
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

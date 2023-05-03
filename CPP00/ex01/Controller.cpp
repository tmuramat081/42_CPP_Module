#include <iostream>
#include "Controller.hpp"

Controller::PhoneBookResponse Controller::route(std::string line)
{
	std::transform(line.begin(), line.end(), line.begin(), ::toupper);
	if (line == "ADD")
	{
		this->_add();
		return OK;

	}
	else if (line == "SEARCH")
	{
		this->_search();
		return OK;
	}
	else if (line == "EXIT")
	{
		this->_exit();
		return OK;
	}
	else
	{
		std::cout << "Invalid command" << std::endl;
		return NG;
	}
}

Controller::PhoneBookResponse Controller::_add(void)
{
	std::string;

	std::cout << "ADD: save a new contact" << std::endl;
	while (true)
	{
		std::cin >> line
	}

	this->book.addContact(contact);
}

Controller::PhoneBookResponse Controller::_search(void)
{
	int index;

	std::cout << "SEARCH: display a specific contact" << std::endl;
	while (true)
	{
		std::cin >> index;
		if (!index)
		{
			break;
		}
		std::cout << "Search... " << index;
		std::cout << std::endl;
		Contact contact = this->book.findContact(index);
	}
}

Controller::PhoneBookResponse Controller::_exit(void)
{
	PhoneBook pb;
}

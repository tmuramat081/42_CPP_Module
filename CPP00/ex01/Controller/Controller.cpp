#include <iostream>
#include <sstream>
#include "Controller.hpp"
#include "PhoneBook.hpp"
#include "PhoneBookView.hpp"

Controller::Controller() {};

Controller::~Controller() {};

void Controller::routeController()
{
	std::string line;
	while (42)
	{
		PhoneBookView::displayInformation();
		std::getline(std::cin, line);
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		if (line == "SEARCH")
		{
			this->findContactController();
		}
		else if (line == "ADD")
		{
			this->createContactController();
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

	while (42)
	{
		std::cout << "Enter any index number" << std::endl;
		std::cin >> index;
		book.findContact(index);
	}
}

void Controller::createContactController(void)
{
	std::string word;
	Contact contact;

	while (42)
	{
		std::cout << "Enter a Fiest Name" << std::endl;
		std::cin >> contact.firstName;
		std::cout << "Enter a Last Name" << std::endl;
		std::cin >> contact.lastName;
		std::cout << "Enter a Nickname" << std::endl;
		std::cin >> contact.nickname;
		std::cout << "Enter a Phone Number" << std::endl;
		std::cin >> contact.phoneNumber;
		std::cout << "Enter a Darkest Secret" << std::endl;
		std::cin >> contact.secret;
		book.createContact(contact);
	}
}

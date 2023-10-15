#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "PhoneBook.hpp"
#include "PhoneBookView.hpp"
#include "PhoneBookValidator.hpp"

class Controller
{
public:
	Controller();
	~Controller();
	void routeController(void);

private:
	PhoneBook phoneBook;
	PhoneBookValidator validator;
	PhoneBookView view;
	void createContactController(void);
	void findContactController(void);
	void exitController(void);
	int readIntegerInput(void);
	std::string readStringInput(const size_t maxLength = 0);
};

#endif

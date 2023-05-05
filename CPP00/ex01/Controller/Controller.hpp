#ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

#include "PhoneBook.hpp"

class Controller
{
public:
	Controller();
	~Controller();
	void routeController(void);
	void createContactController(void);
	void findContactController(void);
	void exitController(void);

private:
	PhoneBook book;
};

#endif
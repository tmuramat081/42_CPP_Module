#ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

#include "PhoneBook.hpp"

class Controller
{
public:
	enum PhoneBookResponse {
		SUCCESS,
		ERROR,
		RESPONSE_EOF,
	};
	enum PhoneBookMode {
		REQUEST_NORMAL,
		REQUEST_GET,
		REQUEST_POST,
	};
	Controller();
	~Controller();
	void routeController();
	void createContactController();
	void findContactController(std::string line);

private:
	PhoneBook book;
	int _state;
	void _add(void);
	void _search(void);
	void _exit(void);
};

#endif
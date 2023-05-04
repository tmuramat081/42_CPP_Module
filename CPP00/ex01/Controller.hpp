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
		MODE_NORMAL,
		MODE_CREATE,
		MODE_FIND,
	};
	Controller();
	~Controller();
	PhoneBookResponse route(std::string line);
	PhoneBookResponse createContactController(std::string line);
	PhoneBookResponse findContactController(std::string line);

private:
	PhoneBook book;
	int _state;
	void _add(void);
	void _search(void);
	void _exit(void);
};

#endif
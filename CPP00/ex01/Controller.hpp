#ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

#include "PhoneBook.hpp"

class Controller
{
public:
	enum PhoneBookResponse {
		OK,
		NG,
		ERROR,
		END,
	};
	Controller(){};
	~Controller(){};
	PhoneBookResponse route(std::string command);

private:
	PhoneBook book;
	void _add(void);
	void _search(void);
	void _exit(void);
};

#endif
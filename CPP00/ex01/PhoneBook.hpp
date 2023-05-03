#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# include <iostream>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void addContact(Contact& contact);
	Contact findContact(int index);

private:
	Contact _contacts[8];
	int	_index;
};

#endif

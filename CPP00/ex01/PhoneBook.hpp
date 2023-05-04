#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "ContactRepository.hpp"
# include <iostream>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void addContact(Contact& contact);
	Contact findContact(int index);

private:
	ContactRepository<Contact> _repository;
	Contact _contacts[8];
	int	_index;
};

#endif
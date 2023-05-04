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

	void createContact(Contact& contact);
	Contact findContact(const int index);

private:
	ContactRepository<Contact> _repository;
	int	_index;
};

#endif
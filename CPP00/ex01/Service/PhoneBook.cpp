#include "PhoneBook.hpp"
#include "Repository.hpp"
#include <iostream>

PhoneBook::PhoneBook(){};

PhoneBook::~PhoneBook()
{

}

void PhoneBook::createContact(Contact& newContact)
{
	// validate
	_repository.add(newContact);
}

Contact PhoneBook::findContact(const int index)
{
	Contact contact = _repository.find(index);
	return contact;
}
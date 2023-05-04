#include "PhoneBook.hpp"
#include "Repository.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	static Contact contacts[8];
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::createContact(Contact& contact)
{

	_repository.add(contact);
}

Contact PhoneBook::findContact(const int index)
{
	Contact contact = _repository.find(index);
	return contact;
}
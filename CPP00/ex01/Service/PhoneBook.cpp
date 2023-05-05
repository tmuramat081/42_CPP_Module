#include "PhoneBook.hpp"
#include "Repository.hpp"
#include <iostream>

PhoneBook::PhoneBook(){};

PhoneBook::~PhoneBook()
{

}

void PhoneBook::createContact(Contact& newContact)
{
	_repository.insert(newContact);
}

Contact PhoneBook::findContact(const int index)
{
	Contact contact = _repository.select(index);
	return contact;
}

FindAllContactsResponse PhoneBook::findAllContacts(Contact *contacts)
{
	`
}

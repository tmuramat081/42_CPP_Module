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

PhoneBook::FindAllContactsResponse PhoneBook::findAllContacts(void)
{
	FindAllContactsResponse response;

	for (int i = 0; i < 8; i++)
	{
		response.contacts[i] = _repository.select(i);
	}
	return response;	
}

#include "PhoneBookConstant.hpp"
#include "PhoneBook.hpp"
#include "Repository.hpp"
#include <iostream>

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook()
{

}

int PhoneBook::createContact(Contact& newContact)
{
	newContact.isDeleted = false;
	int index = _repository.insert(newContact);
	return (index);
}

PhoneBook::FindOneContactResponse PhoneBook::findOneContact(const size_t index)
{
	FindOneContactResponse response;

	try
	{
		response.contact = _repository.select(index);
	}
	catch(...)
	{
		throw "No Object";
	}
	return response;
}

PhoneBook::FindAllContactsResponse PhoneBook::findAllContacts(void)
{
	FindAllContactsResponse response;

	for (int i = 0; i < PhoneBookConstant::RECORD_MAX; ++i)
	{
		response.contacts[i] = _repository.select(i);
	}
	return response;
}

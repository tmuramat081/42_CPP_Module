#include "PhoneBook.hpp"
#include "Repository.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact(Contact& contact)
{
	_repository.add(contact);
}

Contact PhoneBook::findContact(int index)
{
	Contact contact = _repository.find(index);
	return contact;
}

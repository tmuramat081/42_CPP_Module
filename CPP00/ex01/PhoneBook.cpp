#include "PhoneBook.hpp"
#include "Repository.hpp"
#include "ContactRepository.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact(Contact& contact)
{
	repository.add(contact);
}

Contact PhoneBook::findContact(int index)
{
	repository.findAll()
	return c;
}

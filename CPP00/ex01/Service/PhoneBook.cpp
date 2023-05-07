#include "PhoneBookConstant.hpp"
#include "PhoneBook.hpp"
#include "Repository.hpp"
#include <iostream>

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook()
{

}

/** 連絡先を登録する */
int PhoneBook::createContact(Contact& newContact)
{
	newContact.isDeleted = false;
	int index = _repository.insert(newContact);
	return (index);
}

/** 連絡先詳細を取得する */
PhoneBook::FindOneContactResponse PhoneBook::findOneContact(const int index)
{
	FindOneContactResponse response;

	try
	{
		response.contact = _repository.select(index);
		response.index = index;
	}
	catch(...)
	{
		throw "No Object";
	}
	return response;
}

/**　連絡先一覧を取得する */
PhoneBook::FindAllContactsResponse PhoneBook::findAllContacts(void)
{
	FindAllContactsResponse response;

	for (int i = 0; i < PhoneBookConstant::RECORD_MAX; ++i)
	{
		response.contacts[i] = _repository.select(i);
	}
	return response;
}

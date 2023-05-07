#include "PhoneBookConstant.hpp"
#include "PhoneBookValidator.hpp"
#include "PhoneBook.hpp"
#include "Repository.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

/** 連絡先を登録する */
int PhoneBook::createContact(OneContactDto& newContact)
{
	std::string name;

	/** レコード作成　*/
	Contact contact(
		newContact.firstName,
		newContact.lastName,
		newContact.nickname,
		newContact.phoneNumber,
		newContact.secret
	);

	/** レコード追加 */
	int index = _repository.insert(contact);
	return (index);
}

/** 連絡先詳細を取得する */
PhoneBook::OneContactDto PhoneBook::findOneContact(const int index)
{
	Contact	contact;
	OneContactDto response;

	try
	{
		/* レコード取得 */
		contact = _repository.select(index);

		/** レスポンス整形 */
		response.firstName = contact.firstName;
		response.lastName = contact.lastName;
		response.nickname = contact.nickname;
		response.phoneNumber = contact.phoneNumber;
		response.secret = contact.secret;
		response.isDeleted = contact.isDeleted;
		return response;
	}
	catch(...)
	{
		throw "Record Error";
	}
}

/**　連絡先一覧を取得する */
PhoneBook::AllContactsDto PhoneBook::findAllContacts(void)
{
	AllContactsDto response;

	try
	{
		/** レコード全件取得 */
		for (int i = 0; i < PhoneBookConstant::RECORD_MAX; ++i)
		{
			response.contacts[i] = _repository.select(i);
		}
		return response;
	}
	catch (...)
	{
		throw "Record Error.";
	}
}

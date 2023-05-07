#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "ContactRepository.hpp"
#include <iostream>

class PhoneBook
{
public:
	class OneContactDto
	{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;
		bool isDeleted;
	};
	class AllContactsDto
	{
	public:
		Contact contacts[PhoneBookConstant::RECORD_MAX];
	};
	PhoneBook();
	~PhoneBook();

	int createContact(OneContactDto &contact);
	OneContactDto findOneContact(const int index);
	AllContactsDto findAllContacts(void);

private:
	ContactRepository<Contact> _repository;
};

#endif

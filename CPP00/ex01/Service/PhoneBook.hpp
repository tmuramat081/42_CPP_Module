#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "ContactRepository.hpp"
# include <iostream>

class PhoneBook
{
public:
	typedef struct s_findAllContactsResponse{
		Contact contacts[8];
	} FindAllContactsResponse;
	PhoneBook();
	~PhoneBook();

	void createContact(Contact& contact);
	Contact findContact(const int index);
	FindAllContactsResponse findAllContacts(void);

private:
	ContactRepository<Contact> _repository;
};

#endif

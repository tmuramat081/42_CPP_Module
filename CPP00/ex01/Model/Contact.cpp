#include "Contact.hpp"
#include <iostream>

Contact::Contact(
	std::string &firstName,
	std::string &lastName,
	std::string &nickname,
	std::string &phoneNumber,
	std::string &secret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->secret = secret;
	this->isDeleted = false;
}

Contact::Contact() {}

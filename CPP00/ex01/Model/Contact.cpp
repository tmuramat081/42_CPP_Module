#include "Contact.hpp"
#include <iostream>

Contact::Contact(
	int index,
	std::string &firstName,
	std::string &lastName,
	std::string &nickname,
	std::string &phoneNumber,
	std::string &secret)
{
	this->index = index;
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->secret = secret;
};

Contact::Contact(){};
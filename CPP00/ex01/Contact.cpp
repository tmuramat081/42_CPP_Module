#include "Contact.hpp"
#include <iostream>

Contact::Contact(
	int index,
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string secret)
{
	this->index = index;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->secret = secret;
};
Contact::Contact(){};
Contact::~Contact(){};

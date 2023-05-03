#include <iostream>

class Contact
{
	Contact(){};
	Contact(
		int index,
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string secret);

	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
};

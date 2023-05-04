#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

/**
 * @brief Model 連絡先モデルクラス
 *
 */
class Contact
{
public:
	Contact(
		int index,
		std::string &firstName,
		std::string &lastName,
		std::string &nickname,
		std::string &phoneNumber,
		std::string &secret);
	Contact();
	int index;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
};

#endif

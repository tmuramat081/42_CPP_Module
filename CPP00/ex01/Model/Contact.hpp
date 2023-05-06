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
		std::string &firstName,
		std::string &lastName,
		std::string &nickname,
		std::string &phoneNumber,
		std::string &secret);
	Contact();
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
	bool isDeleted;
};

#endif

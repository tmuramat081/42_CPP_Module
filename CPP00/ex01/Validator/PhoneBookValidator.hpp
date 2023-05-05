#ifndef PHONEBOOK_VALIDATOR_HPP
# define PHONEBOOK_VALIDATOR_HPP

#include <iostream>

/** 入力値のバリデーション用クラス */
class PhoneBookValidator
{
public:
	static bool isValidName(const std::string &name);
	static bool isValidPhoneNumber(const std::string &phoneNumber);
};

#endif
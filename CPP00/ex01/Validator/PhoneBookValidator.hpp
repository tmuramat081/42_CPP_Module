#ifndef PHONEBOOK_VALIDATOR_HPP
# define PHONEBOOK_VALIDATOR_HPP

#include <iostream>

/** 入力値のバリデーション用クラス */
class PhoneBookValidator
{
public:
	bool isValidName(const std::string &name);
	bool isValidPhoneNumber(const std::string &phoneNumber);
	bool isValidIndex(const int index);
};

#endif

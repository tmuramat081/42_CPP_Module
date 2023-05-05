#include "PhoneBookValidator.hpp"
#include <iostream>

/** 名前が有効かどうか判定する */
bool PhoneBookValidator::isValidName(const std::string &name)
{
	return !name.empty();
}

/** 電話番号が有効かどうか判定する */
bool PhoneBookValidator::isValidPhoneNumber(const std::string &phoneNumber)
{
	size_t digits_count = 0;

	for (size_t i = 0; i < phoneNumber.length(); ++i)
	{
		if (std::isdigit(phoneNumber[i]))
		{
			++digits_count;
		} else if (phoneNumber[i] != '-' && phoneNumber[i] != ' ')
		{
			return false;
		}
	}
	return digits_count >= 10 && digits_count <= 15;
}
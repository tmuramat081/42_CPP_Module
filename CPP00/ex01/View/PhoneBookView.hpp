#ifndef PHONE_BOOK_VIEW_HPP
#define PHONE_BOOK_VIEW_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"

/**
 * @brief View: 標準出力ビュークラス
 *
 */
class PhoneBookView
{
public:
	static void displayBanner(void);
	static void displayInformation(void);
	static void displayContacts(const PhoneBook::FindAllContactsResponse &response);
	static void displayMessage(const std::string &message);
	static void displayError(const std::string &message);
};

#endif
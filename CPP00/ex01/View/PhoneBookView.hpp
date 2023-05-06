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
	static void displayContacts(const PhoneBook::FindAllContactsResponse &response);
	static void displayOneContact(const PhoneBook::FindOneContactResponse &response);
	static void displayMessage(const std::string &message);
	static void displayError(const std::string &message);
	static std::string truncateString(const std::string &str, const size_t length);
};

#endif

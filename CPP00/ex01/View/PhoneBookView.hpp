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
	void displayBanner(void);
	void displayContacts(const PhoneBook::AllContactsDto &response);
	void displayOneContact(const PhoneBook::OneContactDto &response);
	void displayMessage(const std::string &message);
	void displayError(const std::string &message);

private:
	std::string truncateString(const std::string &str, const size_t length);
};

#endif

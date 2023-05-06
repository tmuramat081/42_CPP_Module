#include "PhoneBookView.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

/** 起動時のバナーを出力する */
void PhoneBookView::displayBanner(void)
{
	std::cout << BLUE;
	std::cout << "  ___ _                 ___           _   " << std::endl;
	std::cout << " | _ \\ |_  ___ _ _  ___| _ ) ___  ___| |__" << std::endl;
	std::cout << " |  _/ ' \\/ _ \\ ' \\/ -_) _ \\/ _ \\/ _ \\ / /" << std::endl;
	std::cout << " |_| |_||_\\___/_||_\\___|___/\\___/\\___/_\\__\\" << std::endl;
	std::cout << "                                          ";
	std::cout << DEFAULT << std::endl;
}

/** 連絡先一覧を出力する */
void PhoneBookView::displayContacts(const PhoneBook::FindAllContactsResponse &response)
{
	std::cout << "+------------------------------------+" << std::endl;
	std::cout << "|No.|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|------------------------------------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(3) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << PhoneBookView::truncateString(response.contacts[i].firstName, 10) << "|";
		std::cout << std::right << std::setw(10) << PhoneBookView::truncateString(response.contacts[i].lastName, 10) << "|";
		std::cout << std::right << std::setw(10) << PhoneBookView::truncateString(response.contacts[i].nickname, 10) << "|";
		std::cout << std::endl;
	}
	std::cout << "+------------------------------------+" << std::endl;
}

/**　連絡先詳細を出力する */
void PhoneBookView::displayOneContact(const PhoneBook::FindOneContactResponse &response)
{
	std::cout << "+------------------------------------+" << std::endl;
	std::cout << "| No." << response.index + 1 << "\t|" << "\tContact Details\t" << std::setw(6) << std::right << "|" << std::endl;
	std::cout << "+------------------------------------+" << std::endl;

	std::cout << std::setw"|First Name: " << response.contact.firstName << std::endl;
	std::cout << "|Last Name: " << response.contact.lastName << std::endl;
	std::cout << "|Nickname: " << response.contact.nickname << std::endl;
	std::cout << "|Phone Number:" << response.contact.phoneNumber << std::endl;
	std::cout << "|Secret: " << response.contact.secret << std::endl;
	std::cout << "+------------------------------------+" << std::endl;
}

std::string PhoneBookView::truncateString(const std::string &str, const size_t length)
{
	if (str.length() <= length)
	{
		return str;
	}
	return str.substr(0, length - 1) + ".";
}

/** メッセージ出力 */
void PhoneBookView::displayMessage(const std::string &message)
{
	std::cout << GREEN;
	std::cout << message;
	std::cout << DEFAULT << std::endl;
}

/** エラー出力　*/
void PhoneBookView::displayError(const std::string &message)
{
	std::cout << RED;
	std::cerr << "Error: " << message << std::endl;
	std::cout << DEFAULT << std::endl;
}

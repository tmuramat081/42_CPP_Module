#include "PhoneBookView.hpp"
#include <iostream>

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

/** 起動時のバナーを出力する */
void displayBanner(void)
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
void displayContacts(const Contact &contact)
{
	std::cout << "|  First Name  |  Last Name |  Nickname | Phone Number | Darkest Secret |" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << contact.firstName;
		std::cout << contact.lastName;
		std::cout << contact.nickname;
		std::cout << contact.phoneNumber;
		std::cout << contact.secret;
	}
	std::cout << std::endl;
}

/** エラー出力　*/
void displayError(const std::string &message)
{
	std::cerr << "Error: " << message << std::endl;
}

void displayInformation(void)
{
	std::cout << RED;
	std::cout << "Enter a command (ADD, SEARCH, or EXIT)";
	std::cout << std::endl;
}
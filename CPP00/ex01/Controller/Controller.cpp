#include <iostream>
#include <sstream>
#include <limits.h>
#include "Controller.hpp"
#include "PhoneBook.hpp"
#include "PhoneBookView.hpp"
#include "PhoneBookValidator.hpp"
#include "PhoneBookConstant.hpp"
#include "MessageConstant.hpp"

Controller::Controller() {}

Controller::~Controller() {}

/** ルート */
void Controller::routeController()
{
	std::string line;

	/** バナー出力 */
	PhoneBookView::displayBanner();
	while (42)
	{
		PhoneBookView::displayMessage(MessageConstant::ENTER_COMMAND);
		std::getline(std::cin, line);
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		if (line == PhoneBookConstant::Command::SEARCH)
		{
			this->findContactController();
		}
		else if (line == PhoneBookConstant::Command::ADD)
		{
			this->createContactController();
		}
		else if (line == PhoneBookConstant::Command::EXIT)
		{
			this->exitController();
		}
		else
		{
			PhoneBookView::displayError(MessageConstant::Error::INVALID_COMMAND);
		}
	}
}

/** 連絡先の取得 */
void Controller::findContactController(void)
{
	std::string index;

	/** 連絡先一覧を取得 */
	PhoneBook::FindAllContactsResponse contacts = book.findAllContacts();

	/** 連絡先一覧をテーブル表示 */
	PhoneBookView::displayContacts(contacts);

	/** インデックスの入力 */
	PhoneBookView::displayMessage(MessageConstant::ENTER_INDEX);
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	PhoneBookValidator::isValidIndex(index);

	/** 連絡先詳細を取得 */
	PhoneBook::FindOneContactResponse contact = book.findOneContact(std::stoi(index) - 1);
	/** 連絡先が存在しない場合はエラーとする */
	if (contact.contact.isDeleted == true)
	{
		PhoneBookView::displayError(MessageConstant::Error::NOT_EXIST_CONTACT);
		return ;
	}

	/** 連絡先詳細を表示 */
	PhoneBookView::displayOneContact(contact);
}

/** 連絡先の登録 */
void Controller::createContactController(void)
{
	std::string word;
	Contact contact;

	std::cout << ">> Enter a First Name" << std::endl;
	std::cin >> contact.firstName;
	std::cout << ">> Enter a Last Name" << std::endl;
	std::cin >> contact.lastName;
	std::cout << ">> Enter a Nickname" << std::endl;
	std::cin >> contact.nickname;
	std::cout << ">> Enter a Phone Number" << std::endl;
	std::cin >> contact.phoneNumber;
	std::cout << ">> Enter a Darkest Secret" << std::endl;
	std::cin >> contact.secret;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	/** 連絡先を登録 */
	book.createContact(contact);
}

void Controller::exitController(void)
{
	std::string line;

	while (true)
	{
		std::cout << MessageConstant::EXIT_CHECK << std::endl;
		std::cin >> line;
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (line == "YES")
		{
			std::cout << MessageConstant::EXIT_APP << std::endl;
			std::exit(EXIT_SUCCESS);
		}
		else if (line == "NO")
		{
			return ;
		}
	}
}


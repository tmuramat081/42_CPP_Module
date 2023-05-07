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
		/** コマンド入力 */
		PhoneBookView::displayMessage(MessageConstant::ENTER_COMMAND);
		line = this->readStringInput();
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
	int index;

	/** 連絡先一覧を取得 */
	PhoneBook::AllContactsDto contacts = phoneBook.findAllContacts();

	/** 連絡先一覧をテーブル表示 */
	PhoneBookView::displayContacts(contacts);

	/** インデックス入力 */
	PhoneBookView::displayMessage(MessageConstant::ENTER_INDEX);
	index = this->readIntegerInput();
	/** 入力値バリデーション */
	if (!PhoneBookValidator::isValidIndex(index))
	{
		PhoneBookView::displayError(MessageConstant::Error::INVALID_INPUT);
		return;
	}

	/** 連絡先詳細を取得 */
	PhoneBook::OneContactDto contact = phoneBook.findOneContact(index - 1);
	/** 連絡先が存在しない場合はエラーとする */
	if (contact.isDeleted == true)
	{
		PhoneBookView::displayError(MessageConstant::Error::NOT_EXIST_CONTACT);
		return;
	}

	/** 連絡先詳細を表示 */
	PhoneBookView::displayOneContact(contact);
}

/** 連絡先の登録 */
void Controller::createContactController(void)
{
	std::string word;
	std::string line;
	PhoneBook::OneContactDto contact;

	/** 新規連絡先の入力 */
	std::cout << ">> Enter a First Name" << std::endl;
	contact.firstName = readStringInput(20);
	std::cout << ">> Enter a Last Name" << std::endl;
	contact.lastName = readStringInput(20);
	std::cout << ">> Enter a Nickname" << std::endl;
	contact.nickname = readStringInput(20);
	std::cout << ">> Enter a Phone Number" << std::endl;
	contact.phoneNumber = readStringInput(20);
	std::cout << ">> Enter a Darkest Secret" << std::endl;
	contact.secret = readStringInput(20);

	/** 入力した連絡先詳細を表示 */
	PhoneBookView::displayOneContact(contact);

	/** 入力確認 */
	PhoneBookView::displayMessage(MessageConstant::CREATE_CHECK);
	while (true)
	{
		line = readStringInput();
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		if (line == PhoneBookConstant::Command::YES)
		{
			break;
		}
		else if (line == PhoneBookConstant::Command::NO)
		{
			return;
		}
	}
	/** 連絡先を登録 */
	phoneBook.createContact(contact);
	std::cout << MessageConstant::CREATE_SUCCESS << std::endl;
}

/** アプリケーションの終了 */
void Controller::exitController(void)
{
	std::string line;

	while (true)
	{
		/** 終了確認 */
		PhoneBookView::displayMessage(MessageConstant::EXIT_CHECK);
		line = this->readStringInput();
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		if (line == PhoneBookConstant::Command::YES)
		{
			PhoneBookView::displayMessage(MessageConstant::EXIT_APP);
			std::exit(EXIT_SUCCESS);
		}
		else if (line == PhoneBookConstant::Command::NO)
		{
			return;
		}
	}
}

/** 標準入力から整数値を読み取る */
int Controller::readIntegerInput(void)
{
	std::string line;
	int number;

	while (true)
	{
		line = this->readStringInput();

		try
		{
			number = std::stoi(line);
			break;
		}
		catch (const std::invalid_argument &e)
		{
			PhoneBookView::displayError(MessageConstant::Error::INVALID_INPUT);
		}
		catch (const std::out_of_range &e)
		{
			PhoneBookView::displayError(MessageConstant::Error::OUT_OF_RANGE);
		}
	}
	return number;
}

/** 標準入力から文字列を読み取る */
std::string Controller::readStringInput(const size_t maxLength)
{
	std::string line;

	while (true)
	{
		if (!std::getline(std::cin, line))
		{
			PhoneBookView::displayMessage(MessageConstant::EXIT_APP);
			std::exit(EXIT_SUCCESS);
		}
		else if (maxLength && line.length() > maxLength)
		{
			PhoneBookView::displayError(MessageConstant::Error::INVALID_LENGTH);
		}
		else
			break;
	}
	return line;
}

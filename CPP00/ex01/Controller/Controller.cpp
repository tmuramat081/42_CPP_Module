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
	view.displayBanner();

	while (42)
	{
		/** コマンド入力 */
		view.displayMessage(MessageConstant::ENTER_COMMAND);
		line = this->readStringInput();
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);

		/** ルーティング */
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
			view.displayError(MessageConstant::Error::INVALID_COMMAND);
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
	view.displayContacts(contacts);

	/** インデックス入力 */
	view.displayMessage(MessageConstant::ENTER_INDEX);
	index = this->readIntegerInput();
	/** 入力値バリデーション */
	if (!validator.isValidIndex(index))
	{
		view.displayError(MessageConstant::Error::INVALID_INPUT);
		return;
	}

	/** 連絡先詳細を取得 */
	PhoneBook::OneContactDto contact = phoneBook.findOneContact(index - 1);
	/** 連絡先が存在しない場合はエラーとする */
	if (contact.isDeleted == true)
	{
		view.displayError(MessageConstant::Error::NOT_EXIST_CONTACT);
		return;
	}

	/** 連絡先詳細を表示 */
	view.displayOneContact(contact);
}

/** 連絡先の登録 */
void Controller::createContactController(void)
{
	PhoneBook::OneContactDto contact;
	std::string line;

	/** 新規連絡先の入力 */
	view.displayMessage(MessageConstant::inputItemMessage(MessageConstant::FIRST_NAME));
	contact.firstName = readStringInput(20);
	view.displayMessage(MessageConstant::inputItemMessage(MessageConstant::LAST_NAME));
	contact.lastName = readStringInput(20);
	view.displayMessage(MessageConstant::inputItemMessage(MessageConstant::NICKNAME));
	contact.nickname = readStringInput(20);
	view.displayMessage(MessageConstant::inputItemMessage(MessageConstant::PHONE_NUMBER));
	contact.phoneNumber = readStringInput(20);
	view.displayMessage(MessageConstant::inputItemMessage(MessageConstant::SECRET));
	contact.secret = readStringInput(20);

	if (!validator.isValidName(contact.firstName) || !validator.isValidName(contact.lastName))
	{
		view.displayError(MessageConstant::Error::INVALID_NAME);
		return;
	}
	else if (!validator.isValidPhoneNumber(contact.phoneNumber))
	{
		view.displayError(MessageConstant::Error::INVALID_PHONE_NUMBER);
		return ;
	}

	/** 入力した連絡先詳細を表示 */
	view.displayOneContact(contact);

	/** 入力確認 */
	view.displayMessage(MessageConstant::CREATE_CHECK);
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
		view.displayMessage(MessageConstant::EXIT_CHECK);
		line = this->readStringInput();
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		if (line == PhoneBookConstant::Command::YES)
		{
			view.displayMessage(MessageConstant::EXIT_APP);
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
			view.displayError(MessageConstant::Error::INVALID_INPUT);
		}
		catch (const std::out_of_range &e)
		{
			view.displayError(MessageConstant::Error::OUT_OF_RANGE);
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
			view.displayMessage(MessageConstant::EXIT_APP);
			std::exit(EXIT_SUCCESS);
		}
		else if (line.length() == 0)
		{
			view.displayError(MessageConstant::Error::EMPTY_LINE);
		}
		else if (maxLength && line.length() > maxLength)
		{
			view.displayError(MessageConstant::Error::INVALID_LENGTH);
		}
		else
			break;
	}
	return line;
}

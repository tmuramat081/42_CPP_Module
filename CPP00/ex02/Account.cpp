#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return t::_nbAccounts;
}

int Account::getTotalAmount()
{
	return t::_totalAmount;
}

int Account::getNbDeposits()
{
	return t::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return t::_totalNbWithdrawals;
}

/** 全インスタンスの口座情報を表示 */
void Account::displayAccountsInfos()
{
	t::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return;
}

Account::Account(int initial_deposit)
{
	t::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	t::_nbAccounts += 1;
	t::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/**　インスタンスの口座への預け入れ */
void Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;
	this->_amount += deposit;
	t::_totalAmount += deposit;
	this->_nbDeposits += 1;
	t::_totalNbDeposits += 1;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/** インスタンスの口座からの引き出し */
bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:";
		std::cout << "refused" << std::endl;
		return false;
	}
	int p_amount = this->_amount;
	this->_amount -= withdrawal;
	t::_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	t::_totalNbWithdrawals += 1;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

/** わからん */
int Account::checkAmount(void) const
{
	return this->_amount;
}

/**　インスタンスの口座情報を表示 */
void Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/** 現在時刻の表示 */
void Account::_displayTimestamp()
{
	std::tm past_time = {};
	char buffer[20];

	past_time.tm_year = 92;
    past_time.tm_mon = 0;
    past_time.tm_mday = 4;
    past_time.tm_hour = 9;
    past_time.tm_min = 15;
    past_time.tm_sec = 32;

	std::time_t timestamp = std::mktime(&past_time);
	std::tm *localtime = std::localtime(&timestamp);
	std::strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", localtime);
	std::cout << buffer;
}

Account::Account(){}

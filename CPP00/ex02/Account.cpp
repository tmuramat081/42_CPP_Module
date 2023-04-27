#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Construct a new Account:: Account object
 *
 */
Account::Account(int initial_deposit)
{
	Account::_totalAmount = initial_deposit;
	std::cout << "index:" << this->_nbAccounts << ";";
	std::cout  << "acount" << this->_totalAmount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	return ;
}

int Account::getNbAccounts()
{
	return Account::_nbAccounts;
}
int Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	return;
}

void Account::makeDeposit(int deposit)
{

}

bool Account::makeWithdrawal(int withdrawal)
{
	return true;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const {
	return ;
}
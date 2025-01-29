#include "Account.hpp"

#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(const int initial_deposit) :
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
}


int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos()
{
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(const int deposit)
{
	_amount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(const int withdrawal)
{
	if (withdrawal > _amount)
		return false;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	std::cout << "hey there";
}

void Account::_displayTimestamp()
{
	const std::time_t timestamp = std::time(NULL);
	const std::tm* now = std::localtime(&timestamp);

	std::cout << "[" << (now->tm_year + 1900)
		<< (now->tm_mon + 1 < 10 ? "0" : "") << now->tm_mon + 1
		<< (now->tm_mday < 10 ? "0" : "") << now->tm_mday + 1
		<< "_" << (now->tm_hour < 10 ? "0" : "") << now->tm_hour
		<< (now->tm_min < 10 ? "0" : "") << now->tm_min
		<< (now->tm_sec < 10 ? "0" : "") << now->tm_sec
		<< "] ";
}

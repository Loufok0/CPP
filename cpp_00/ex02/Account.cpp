#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initialDeposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initialDeposit;
	_totalAmount += initialDeposit;
	this->_accountIndex = initialDeposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits" << getNbDeposits() << ";withdrawals" << getNbWithdrawals() << std::endl;
}


void	Account::displayStatus (void) const
{
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << "initial - total?" << ";amount:" << this->_amount << ";nb_deposits" << this->_nbDeposits << std::endl;
}



// deposits et withdrawals negatifs ?



void	Account::makeDeposit(int deposit)
{
	this->_totalNbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true); // ?????????????????????????????????????????????????????
}

int		Account::checkAmount(void) const
{
	return (1); // ??????????????????????????????????????????????????????
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

 int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

 int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

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
	std::cout << "accounts:" << this->getNbAccounts << ";total:" << this->_getTotalAmount << ";deposits" << this->_getNbDeposits << ";withdrawals" << this->_getNbWithdrawals << std::endl;
}


void	Account::displayStatus (void)
{
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << "initial - total?" << ";amount:" << this->_amount << ";nb_deposits" << this->_nbDeposits << std::endl;
}



// deposits et withdrawals negatifs ?



void	Account::makeDeposit(int deposit)
{
	this->nb_deposits++;
	this->_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->nb_withdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
}

int		Account::checkAmount(void)
{

}

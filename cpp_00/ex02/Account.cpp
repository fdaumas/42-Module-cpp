#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_amount = initial_deposit;
	this->_nbAccounts++;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount() << ";deposit:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:"
		<< this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
		<< ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";amount:";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts() {
	return (_nbAccounts);
}

int Account::getTotalAmount() {
	return (_totalAmount);
}

void Account::_displayTimestamp() {
	time_t now = time(0);
	tm *timer = localtime(&now);
	std::cout << "[" << timer->tm_year + 1900 << timer->tm_mon + 1 << timer->tm_mday << "_" << timer->tm_hour << timer->tm_min << timer->tm_sec << "] ";
}
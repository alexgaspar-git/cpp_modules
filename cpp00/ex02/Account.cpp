#include "Account.hpp"
#include <time.h>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << initial_deposit << ";";
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits    = 0;
    _nbWithdrawals = 0;
    std::cout << "created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp(void ) {

	time_t		now = time(0);
	struct tm	*local_time = localtime(&now);
	char		timestamp[20];

	strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", local_time);
	std::cout << "[" << timestamp << "] " ;
	
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if ( withdrawal > _amount ) {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << "withdrawal:" << withdrawal << ";";
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const {
	 return _amount >= 0; 
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

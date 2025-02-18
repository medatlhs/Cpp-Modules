#include "../includes/Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbAccounts += 1;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

void    Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" <<
        _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
            << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() - deposit << ";deposit:"
        << deposit << ";amount:" << checkAmount() << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:";
    if(withdrawal > _amount) {
        std::cout << "refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:"
        << _nbWithdrawals << std::endl;
    return true;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() 
        << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t passedSeconds = std::time(0);
    std::tm     *localTime = std::localtime(&passedSeconds);

    std::cout << "[" << 1900 + localTime->tm_year << localTime->tm_mon + 1;
    std::cout << localTime->tm_mday << "_";
    if (localTime->tm_hour < 10)
        std::cout << "0";
    std::cout << localTime->tm_hour << localTime->tm_min;
    std::cout << localTime->tm_sec << "] ";
}

int Account::checkAmount() const {
    return(_amount);
}

int Account::getNbAccounts() {
    return (_nbAccounts);
}

int Account::getTotalAmount() {
    return (_totalAmount);
}

int Account::getNbDeposits() {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return(_totalNbWithdrawals);
}

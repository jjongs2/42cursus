#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account(int initial_deposit) {
  this->_accountIndex = _nbAccounts;
  _nbAccounts += 1;
  this->_amount = initial_deposit;
  _totalAmount += initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << '\n';
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  int p_amount = this->_amount;
  this->_amount += deposit;
  _totalAmount += deposit;
  this->_nbDeposits += 1;
  _totalNbDeposits += 1;
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
            << ";deposit:" << deposit << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  int p_amount = this->_amount;
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount;
  if (this->checkAmount() < withdrawal) {
    std::cout << ";withdrawal:refused" << '\n';
    return false;
  }
  this->_amount -= withdrawal;
  _totalAmount -= withdrawal;
  this->_nbWithdrawals += 1;
  _totalNbWithdrawals += 1;
  std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals << '\n';
  return true;
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << '\n';
};

void Account::_displayTimestamp(void) {
  time_t timestamp = time(NULL);
  struct tm *time_struct = localtime(&timestamp);
  char buffer[19];
  std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", time_struct);
  std::cout << buffer;
}

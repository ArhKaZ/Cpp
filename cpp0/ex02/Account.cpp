/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:08:29 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/18 13:27:24 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Account.hpp"
#include <iostream>
#include <time.h>
#include <iomanip>

Account::Account( void )
{
	Account::_nbAccounts += 1;
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 1;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits += 1;
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created" << std::endl;
    return ;
}

Account::~Account( void )
{
	Account::_nbAccounts -= 1;
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";closed" << std::endl;
    return ;
}

int Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << Account::_nbAccounts << ";total:"
	<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	return ;
}

int	Account::checkAmount( void ) const 
{
	return (this->_amount);
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal >= checkAmount())
		return (false);
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
	return (true);
}

void displayAccountsInfos( void )
{
	time_t now_time = time(NULL);

	tm *timeinfo = localtime(&now_time);

	std::cout << "[" << timeinfo->tm_year << std::setw(4) << timeinfo->tm_mon
	<< timeinfo->tm_mday << "_" << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << std::endl;
}
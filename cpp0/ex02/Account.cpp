/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:08:29 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 11:17:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Account.hpp"
#include <iostream>
#include <time.h>
#include <iomanip>

Account::Account( void )
{
	_nbAccounts += 1;
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount << ";created" << std::endl;
	return ;
}

Account::Account( int initial_deposit )
{
	_nbAccounts += 1;
    _amount = initial_deposit;
    _nbDeposits = 1;
	_totalAmount += initial_deposit;
	_totalNbDeposits += 1;
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount << ";created" << std::endl;
    return ;
}

Account::~Account( void )
{
	_nbAccounts -= 1;
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount << ";closed" << std::endl;
    return ;
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << _nbAccounts << ";total:"
	<< _totalAmount << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	return ;
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal >= checkAmount())
		return (false);
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	_nbWithdrawals += 1;
	return (true);
}

void displayAccountsInfos( void )
{
	time_t now_time = time(NULL);

	tm *timeinfo = localtime(&now_time);

	std::cout << "[" << timeinfo->tm_year << std::setw(4) << timeinfo->tm_mon
	<< timeinfo->tm_mday << "_" << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << std::endl;
}

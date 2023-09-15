/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:08:29 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/15 15:13:08 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account( void )
{
	this->_nbAccounts += 1;
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::Account( int initial_deposit )
{
	this->_nbAccounts += 1;
    this->_amount = initial_deposit;
    this->_nbDeposits += 1;
	this->_totalAmount += initial_deposit;
	this->_totalNbDeposits += 1;
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created" << std::endl;
    return ;
}

Account::~Account( void )
{
	this->_nbAccounts -= 1;
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";closed" << std::endl;
    return ;
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_nbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_nbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	std::cout << _accountIndex << " "
	<< _amount << " " << _nbDeposits
	<< " " << _nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits += 1;
	this->_nbDeposits += 1;
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
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
	return (true);
}
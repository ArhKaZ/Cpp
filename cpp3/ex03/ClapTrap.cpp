/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:08:52 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 12:55:55 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Basic constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << "Name constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead " << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is tired " << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead " << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage " << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
		if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead " << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is tired " << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " heal " << amount << " hit points " << std::endl;
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::sethp(unsigned int amount)
{
	this->_hitPoints = amount;
}

void	ClapTrap::setep(unsigned int amount)
{
	this->_energyPoints = amount;
}

void	ClapTrap::setad(unsigned int amount)
{
	this->_attackDamage = amount;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int ClapTrap::gethp() const 
{
	return (this->_hitPoints);	
}

unsigned int ClapTrap::getep() const 
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getad() const
{
	return (this->_attackDamage);
}
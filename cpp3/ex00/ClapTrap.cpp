/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:48:05 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/04 14:55:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hit_points = 10;
	std::cout << "Constructor" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hit_points = 10;
	std::cout << "Constructor with name" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is tired" << std::endl;
		return ;
	}
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_energy_points -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->_hit_points - (int)amount) < 0)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damages" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_hit_points;
	if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is tired" << std::endl;
		return ;
	}
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_energy_points -= 1;
	this->_hit_points += amount;
	std::cout << "ClapTrap " << this->_name << " is repaire of " << amount << " hit points" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:45:58 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 14:06:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setName(name);
	this->setad(20);
	this->sethp(100);
	this->setep(50);
	std::cout << "Name constructor for ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor for ScavTrap" << std::endl;
}

void	ScavTrap::attack(const std::string& target) 
{
	if (this->gethp() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead " << std::endl;
		return ;
	}
	if (this->getep() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is tired " << std::endl;
		return;
	}
	this->setep(this->getep() - 1);
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}

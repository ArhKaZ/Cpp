/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:12:05 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 14:16:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setName(name);
	this->sethp(100);
	this->setep(100);
	this->setad(30);
	std::cout << "Name constructor FragTrap" << std::endl;
}

FragTrap::~FragTrap() 
{
	std::cout << "Desctructor FragTrap" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " want to high five !" << std::endl;
}
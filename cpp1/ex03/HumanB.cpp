/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:54:47 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 15:17:38 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	return ;
}

HumanB::~HumanB( void)
{
	return ;
}

void HumanB::attack( void ) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType();
}

void HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
	return ;
}

Weapon HumanB::getWeapon( void )
{
	return (*(this->_weapon));
}

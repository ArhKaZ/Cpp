/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:40:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 15:06:31 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
    std::cout << "Weapon construct\n";
	return ;
}

Weapon::Weapon(std::string type)
{
    std::cout << "Weapon construct\n";
	this->_type = type;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon destroyed\n";
	return ;
}

std::string Weapon::getType()
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
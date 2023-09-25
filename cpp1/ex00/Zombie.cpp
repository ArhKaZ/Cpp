/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:01:11 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 11:38:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Zombie.hpp"

Zombie::Zombie(const std::string name) : _name(name)
{
	std::cout << name << " created\n";
	return ;
}

Zombie::Zombie() :_name("NULL") {
	return ;
}

Zombie::~Zombie() {
	std::cout << this->_name << " destroyed" << std::endl;
	return ;
}

void Zombie::announce() const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

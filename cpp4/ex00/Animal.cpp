/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:30:43 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 09:46:43 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Animal.hpp"

Animal::Animal()
{
	this->type = "Basic";
	std::cout << "Constructor of type Animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor of type Animal" << this->type << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "*Bruit sourd*" << std::endl;
}

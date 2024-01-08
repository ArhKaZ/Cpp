/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:30:43 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 10:37:13 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Animal.hpp"

Animal::Animal()
{
	this->type = "Basic";
	std::cout << "Constructor of type " << this->type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor of type " << this->type << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound()
{
	if (this->type == "Dog")
		std::cout << "Woof Woof" << std::endl;
	if (this->type == "Cat")
		std::cout << "Moewwwwwwwwwww" << std::endl;
	if (this->type == "Basic")
		std::cout << "*Bruit sourd*" << std::endl;
}

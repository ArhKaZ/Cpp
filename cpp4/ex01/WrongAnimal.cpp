/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:50:10 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 15:55:03 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongBasic";
	std::cout << "Constructor of type " << this->type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of type " << this->type << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	if (this->type == "Dog")
		std::cout << "Woof Woof" << std::endl;
	if (this->type == "Cat")
		std::cout << "Moewwwwwwwwwww" << std::endl;
	if (this->type == "Basic")
		std::cout << "*Bruit sourd*" << std::endl;
	if (this->type == "WrongCat" || this->type == "WrongBasic")
		std::cout << "*Bruit pas sourd*" << std::endl;
}
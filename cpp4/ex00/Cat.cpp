/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:40:10 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 09:47:05 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Constructor of type " << this->type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor of type " << this->type << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Moewwwwwwwwwww" << std::endl;
}

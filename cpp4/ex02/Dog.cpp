/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:45 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 10:19:58 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Dog.hpp"
#include "incs/Brain.hpp"

Dog::Dog() : Animal()
{
	this->_brain = new Brain();
	this->type = "Dog";
	std::cout << "Constructor of type " << this->type << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Destructor of type " << this->type << std::endl;
}

void	Dog::makeSound(void)
{
	std::cout << "Woof Woof" << std::endl;
}

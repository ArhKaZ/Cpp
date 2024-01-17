/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:45 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 21:53:33 by syluiset         ###   ########.fr       */
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

void	Dog::print_ideas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->get_ideas(i).compare("") != 0)
			std::cout << this->_brain->get_ideas(i) << std::endl;
	}
}

void	Dog::add_idea(std::string idea, int index)
{
	this->_brain->set_ideas(idea, index);
}

Dog	&Dog::operator=(const Dog &c)
{
	this->_brain->copy_ideas(*c._brain);
	return (*this);
}
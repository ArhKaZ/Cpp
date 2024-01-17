/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:40:10 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 21:53:07 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Cat.hpp"
#include "incs/Brain.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Constructor of type " << this->type << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Destructor of type " << this->type << std::endl;
}

void	Cat::print_ideas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->get_ideas(i).compare("") != 0)
			std::cout << this->_brain->get_ideas(i) << std::endl;
	}
}

void	Cat::add_idea(std::string idea, int index)
{
	this->_brain->set_ideas(idea, index);
}

Cat	&Cat::operator=(const Cat &c)
{
	this->_brain->copy_ideas(*c._brain);
	return (*this);
}
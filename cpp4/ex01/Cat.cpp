/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:40:10 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 10:00:39 by syluiset         ###   ########.fr       */
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

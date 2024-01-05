/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:45 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 16:00:16 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Dog.hpp"
#include "incs/Brain.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->Brain = new Brain();
	std::cout << "Constructor of type " << this->type << std::endl;
}

Dog::~Dog()
{
		std::cout << "Destructor of type " << this->type << std::endl;
}
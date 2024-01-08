/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:45 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 15:36:39 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Constructor of type " << this->type << std::endl;
}

Dog::~Dog()
{
		std::cout << "Destructor of type " << this->type << std::endl;
}
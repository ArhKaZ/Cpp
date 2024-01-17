/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:58:54 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 21:50:48 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain" << std::endl;
}

void Brain::set_ideas(std::string idea, int index)
{
	this->ideas[index] = idea;
}

std::string Brain::get_ideas(int index)
{
	return (this->ideas[index]);
}

void	Brain::copy_ideas(Brain &brain)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
}
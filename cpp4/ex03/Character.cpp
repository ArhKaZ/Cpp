/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:00:41 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 11:02:09 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Character.hpp"

Character::Character()
{
	std::cout << "Character Constructor" << std::endl;
}

Character::~Character()
{
	delete this->Inventory;
	std::cout << "Character Destructor" << std::endl;
}

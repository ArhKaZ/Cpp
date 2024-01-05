/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:28:59 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 15:43:41 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
	protected :
	std::string type;
	
	public :
	Animal();
	virtual ~Animal();
	void virtual makeSound() const;
	std::string	getType() const;
};

#endif
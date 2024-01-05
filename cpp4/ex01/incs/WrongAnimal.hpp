/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:44:58 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 15:46:17 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include "Animal.hpp"

class WrongAnimal {
	protected :
	std::string type;
	
	public :
	WrongAnimal();
	virtual ~WrongAnimal();
	void virtual makeSound() const;
	std::string	getType() const;
};

#endif

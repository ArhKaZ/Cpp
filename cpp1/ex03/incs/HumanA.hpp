/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:43:52 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 14:59:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
	std::string _name;
	Weapon		_weapon;
public:
	HumanA(std::string name, Weapon weapon);
	~HumanA( void );
	void attack( void );
};
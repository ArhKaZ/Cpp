/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:43:52 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/26 11:53:31 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    Weapon&		_weapon;
	std::string _name;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA( void );
	void attack( void );
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:48:44 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 15:05:18 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon*		_weapon;
public:
	HumanB(std::string name);
	~HumanB( void );
	void attack( void ) const ;
	void setWeapon(Weapon weapon);
	Weapon getWeapon( void );
};

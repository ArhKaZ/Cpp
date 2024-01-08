/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:48:44 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/04 12:29:44 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP
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
	void setWeapon(Weapon &weapon);
	Weapon getWeapon( void );
};
#endif

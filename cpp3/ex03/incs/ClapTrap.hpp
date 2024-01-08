/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:09:20 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 14:05:16 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
	private :
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

	public :
	ClapTrap();
	ClapTrap(std::string name);
	virtual ~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setName(std::string name);
	void sethp(unsigned int amount);
	void setep(unsigned int amount);
	void setad(unsigned int amount);
	std::string getName() const;
	unsigned int gethp() const;
	unsigned int getep() const;
	unsigned int getad() const;
	
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:38:46 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 14:18:18 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ScavTrap.hpp"
#include "incs/FragTrap.hpp"

int main()
{
	ClapTrap ct1("sisi");
	ScavTrap st1("robot");
	FragTrap ft1("bonGars");
	ct1.attack(st1.getName());
	st1.takeDamage(ct1.getad());
	st1.beRepaired(30);
	st1.attack(ct1.getName());
	ct1.takeDamage(st1.getad());
	st1.guardGate();
	ft1.highFivesGuys();
	return (0);
}
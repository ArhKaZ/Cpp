/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:30:39 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/04 14:54:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap CT1("Fox");
	ClapTrap CT2("Falco");
	ClapTrap CT3("Snake");
	ClapTrap CT4("Ness");
	
	CT1.attack("Falco");
	CT2.takeDamage(5);
	CT2.beRepaired(9);
	CT2.attack("Fox");
	CT1.takeDamage(4);
	CT1.beRepaired(20);
	for (int i = 0; i < 10; i++)
	{
		CT1.attack("Falco");
		CT2.takeDamage(5);
		CT2.beRepaired(9);
	}
	CT3.attack("Ness");
	CT4.takeDamage(70);
	CT4.beRepaired(30);
	return (0);
}

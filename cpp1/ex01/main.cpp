/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:57:43 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 14:01:36 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name);
Zombie* newZombie( std::string name);
void randomChump( std::string name);

int main()
{
	int i;
	Zombie	*horde = zombieHorde(6, "monZem");

	for (i = 0; i < 6; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}
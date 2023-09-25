/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:57:43 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 11:40:33 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Zombie.hpp"

Zombie* newZombie( std::string name);
void randomChump( std::string name);

int main()
{
	Zombie *theZ = newZombie("theZ");

	theZ->announce();
	randomChump("leZv2");
	delete theZ;
}
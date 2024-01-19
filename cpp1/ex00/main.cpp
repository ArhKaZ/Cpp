/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:57:43 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/20 00:14:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Zombie.hpp"

Zombie* newZombie( std::string name);
void randomChump( std::string name);

int main()
{
	Zombie *theZ = newZombie("theZ");
	Zombie *theZv2 = new Zombie("theZv2");
	theZ->announce();
	theZv2->announce();
	randomChump("leZv3");
	delete theZv2;
	delete theZ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:38:11 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 11:38:59 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Zombie.hpp"

void randomChump(std::string name)
{
	Zombie	theZ = Zombie(name);
	theZ.announce();
	return ;
}
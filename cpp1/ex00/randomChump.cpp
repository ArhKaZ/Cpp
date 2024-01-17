/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:38:11 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 16:10:35 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Zombie.hpp"

void randomChump(std::string name)
{
	Zombie	*theZ = new Zombie(name);
	theZ->announce();
	delete theZ;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:00:32 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 11:31:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie	*theZ = new Zombie(name);
	return (theZ);
}
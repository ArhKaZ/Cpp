/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:50:36 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 11:36:50 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(const std::string name);
	~Zombie();
	void announce( void ) const ;
	void setName(std::string name);
private:
	std::string _name;
};

#endif
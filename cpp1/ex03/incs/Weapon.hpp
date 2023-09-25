/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:37:50 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/25 14:43:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon {
private:
	std::string _type;
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	std::string getType(void);
	void setType(std::string type);
};
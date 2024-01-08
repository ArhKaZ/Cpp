/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:04:35 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 11:07:01 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Materia.hpp"

Materia::Materia(std::string const &type)
{
	this->_type = type;
	std::cout << "Material constructor" << std::endl;
}

Materia::~Materia()
{
	std::cout << "Materia destructor" << std::endl;
}

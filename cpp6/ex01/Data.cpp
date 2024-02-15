/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:42:05 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 14:47:23 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Data.hpp"

Data::Data()
{
	return;
}

Data::~Data()
{
	return;
}

Data::Data(const Data &Data)
{
	this->_value = Data._value;
}

Data &Data::operator=(const Data &Data)
{
	this->_value = Data._value;
	return *this;
}

Data::Data(unsigned long value) {
	this->_value = value;
}

unsigned long Data::get_value() {
	return (this->_value);
}
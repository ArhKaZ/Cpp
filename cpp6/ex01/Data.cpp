/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:42:05 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/23 12:45:03 by syluiset         ###   ########.fr       */
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

Data::Data(int value) {
	this->_value = value;
}

int Data::get_value() {
	return (this->_value);
}
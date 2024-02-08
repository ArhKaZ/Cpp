/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASerializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:35:42 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/23 12:52:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ASerializer.hpp"

Data* ASerializer::deserialize(uintptr_t raw)
{
	return (Data(*raw));
}

uintptr_t ASerializer::serialize(Data *ptr)
{
	return (&<static_cast>(int)ptr->get_value());
}
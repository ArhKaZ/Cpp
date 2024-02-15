/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASerializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:35:42 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 14:41:52 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ASerializer.hpp"

Data* ASerializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t ASerializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:17:57 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/16 15:51:28 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include "iostream"

template< typename T>
void iter(T array[], int length, bool (*f)(T, T))
{
	for (int i = 0; i < length - 1; i++)
	{
		if (f(array[i], array[i + 1]))
		{
			T tmp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = tmp;
		}
	}
}

template<typename T>
bool	this_bigger_than_next(T arg1, T arg2)
{
	if (arg1 > arg2)
		return (true);
	return (false);
}

#endif
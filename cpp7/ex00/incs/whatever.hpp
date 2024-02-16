/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTemp.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:19:07 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/16 15:42:11 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template< typename T >
void swap(T &arg1, T &arg2)
{
	T tmp;
	tmp = arg2;
	arg2 = arg1;
	arg1 = tmp;
}

template<typename T>
T	min(T arg1, T arg2)
{
	if (arg1 > arg2)
		return (arg2);
	if (arg1 < arg2)
		return (arg1);
	return (arg2);
}

template <typename T>
T	max(T arg1, T arg2)
{
	if (arg1 > arg2)
		return (arg1);
	if (arg1 < arg2)
		return (arg2);
	return (arg2);
}

#endif
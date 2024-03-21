/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:17:15 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/20 14:06:40 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

template< typename T >
void easyfind(T arg1, int arg2)
{
	typename T::iterator res;

	res = std::find(arg1.begin(), arg1.end(), arg2);
	if (res == arg1.end())
		throw std::exception();
	else
		std::cout << arg2 << " is on the list" << std::endl;
}

#endif
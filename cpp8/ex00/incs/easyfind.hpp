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
#include <iostream>

template< typename T >
int easyfind(T arg1, int arg2)
{
	typename T::const_iterator it;
	typename T::const_iterator end = arg1.end();
	for(it = arg1.begin(); it != end; it++)
	{
		if (*it == arg2)
		{
			std::cout << arg2 << " find in the list" << std::endl;
			return (0);
		}
	}
	std::cout << arg2 << " not in the list" << std::endl;
	return (-1);
}

#endif
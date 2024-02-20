/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:14:11 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/20 13:37:27 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/easyfind.hpp"

int main()
{
	std::list<int>		lst1;
	std::vector<int>	v1;
	std::
	lst1.push_back(412);
	lst1.push_back(-25409);
	lst1.push_back(3125);
	lst1.push_back(1203);

	v1.push_back(-123124);
	v1.push_back(1283);
	v1.push_back(1239123);
	v1.push_back(-1234124);

	easyfind(lst1, 1205);
	easyfind(lst1, 3125);
	easyfind(v1, -124);
	easyfind(v1, -1234124);
}
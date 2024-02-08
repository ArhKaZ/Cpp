/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:53:25 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/23 13:12:17 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Data.hpp"
#include "incs/ASerializer.hpp"

int main()
{
	Data d1(5123);
	Data d2(-125);
	int	i = 24123;

	std::cout << "Before serialize : " << d1.get_value() << std::endl;
	std::cout << "After serialize : " << ASerializer::serialize(&d1) << std::endl;
	std::cout << "Before serialize : " << d2.get_value() << std::endl;
	std::cout << "After serialize : " << ASerializer::serialize(&d1) << std::endl;
	std::cout << "Before deserialize : " << i << std::endl;
	std::cout << "After deserialize : " << ASerializer::deserialize(i) << std::endl;
}
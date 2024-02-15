/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:53:25 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 14:52:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Data.hpp"
#include "incs/ASerializer.hpp"

int main()
{
	Data d1(5123);
	Data *d2;
	uintptr_t ptr;
	std::cout << "Adresse before serialize : " << &d1 << std::endl;
	std::cout << "Before serialize : " << d1.get_value() << std::endl;
	ptr = ASerializer::serialize(&d1);
	std::cout << std::hex << "After serialize : " << ptr << std::endl;
	d2 = ASerializer::deserialize(ptr);
	std::cout << "Adresse after deserialize : " << d2 << std::endl;
	std::cout << std::dec <<  "Value after deserialize : " << d2->get_value() << std::endl;


}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:24:39 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/16 15:50:05 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Iter.hpp"

int main()
{
	int tabInt[] = {41, 1243, 4512, 1242, 745, 874362, 123521, 9845, 123123, 493853};
	std::string tabString[] = {"J'aime", "J'adore", "Donne", "Mon", "Briquet", "Falacieux", "Paraboy"};

	for(int i = 0; i < 10; i++)
	{
		std::cout << tabInt[i] << " ";
	}
	std::cout << std::endl;
	::iter<int>(tabInt, 10, &this_bigger_than_next);
	for(int i = 0; i < 10; i++)
	{
		std::cout << tabInt[i] << " ";
	}
	std::cout << std::endl;
	for(int i = 0; i < 7; i++)
	{
		std::cout << tabString[i] << " ";
	}
	std::cout << std::endl;
	::iter<std::string>(tabString, 7, &this_bigger_than_next);
	for(int i = 0; i < 7; i++)
	{
		std::cout << tabString[i] << " ";
	}
	std::cout << std::endl;
}
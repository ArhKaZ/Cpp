/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:47 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/20 20:21:18 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Span.hpp"
#include <algorithm>
void display_number(int nb)
{
	std::cout << "nb : " << nb << "|| " ;
}

int main()
{
	Span sp = Span(5);
	Span sp2 = Span(6);
	Span sp3 = Span(100000);
	Span sp4 = Span(2);
	srand(time(NULL));
	std::list<int>::iterator 
	for(unsigned int i = 0; i < sp3.getMax(); i++)
	{
		sp3.addNumber(rand() % 100000 + 1);
	}
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortestSpan for sp : " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan for sp : " << sp.longestSpan() << std::endl;
	sp2.addNumber(34);
	sp2.addSeveralNumber(sp.getList(), 1, 5);

	std::cout << "\n";
	sp2.addNumber(42);
	for_each(sp2.getList().begin(), sp2.getList().end(), display_number);
	std::cout << std::endl;
	std::cout << "shortestSpan for sp3 : " << sp3.shortestSpan() << std::endl;
	std::cout << "longestSpan for sp3 : " << sp3.longestSpan() << std::endl;
	try
	{
		std::cout << "Add a number in sp3 which is full : " << std::endl;
		sp3.addNumber(42);
		std::cout << "It work !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Add a number in sp2 which is full" << std::endl;
		sp2.addNumber(42);
		std::cout << "It work !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Add several number of sp3 list in sp2" << std::endl;
		sp2.addSeveralNumber(sp3.getList(), 531, 1000);
		std::cout << "It work !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "longestSpan in sp4 : " << sp4.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	sp4.addNumber(42);
	try
	{
		std::cout << "shortestSpan in sp4 : " << sp4.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
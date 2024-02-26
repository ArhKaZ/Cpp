/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:21 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"

int main()
{
	Bureaucrat *BuMidLvl = new Bureaucrat("Sylvain", 10);
	Bureaucrat *BuHighLvl = new Bureaucrat("Antoine", 2);
	Bureaucrat *BuLowLvl = new Bureaucrat("Xavier", 149);
	Bureaucrat *BuTooLow;
	Bureaucrat *BuTooHigh;
	try
	{
		BuTooLow = new Bureaucrat("Bidon", 3240);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		BuTooHigh = new Bureaucrat("Bidon2", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	BuLowLvl->downGrade();
	try
	{
		BuLowLvl->downGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	BuHighLvl->incrGrade();
	try
	{
		BuHighLvl->incrGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *BuMidLvl;
	std::cout << *BuHighLvl;
	std::cout << *BuLowLvl;
	delete BuMidLvl;
	delete BuHighLvl;
	delete BuLowLvl;
}

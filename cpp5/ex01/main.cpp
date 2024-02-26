/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:14:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat *BuMidLvl = new Bureaucrat("Sylvain", 10);
	Bureaucrat *BuHighLvl = new Bureaucrat("Antoine", 2);
	Bureaucrat *BuLowLvl = new Bureaucrat("Xavier", 149);
    Form *FormC1234 = new Form("C1234", 5, 16);
    Form *FormC124 = new Form("C124", 39, 140);
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
	std::cout << *BuHighLvl;
	std::cout << *BuMidLvl;
	std::cout << *BuLowLvl;
    std::cout << *FormC1234;
    std::cout << *FormC124;
    std::cout << "FormC1234 sign : " << FormC1234->getSign() << std::endl;
	try
	{
		FormC1234->beSigned(*BuLowLvl);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    FormC1234->beSigned(*BuHighLvl);
    std::cout << "FormC1234 sign : " << FormC1234->getSign() << std::endl;
	try
	{
		BuLowLvl->signForm(*FormC124);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    BuMidLvl->signForm(*FormC124);
	delete BuMidLvl;
	delete BuHighLvl;
	delete BuLowLvl;
    delete FormC1234;
    delete FormC124;
}

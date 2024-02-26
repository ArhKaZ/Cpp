/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/10 14:28:28 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"
#include "incs/AForm.hpp"
#include "incs/PresidentialPardonForm.hpp"
#include "incs/ShrubberyCreationForm.hpp"
#include "incs/RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat *BuMidLvl = new Bureaucrat("Fifi", 42);
	Bureaucrat *BuMidHighLvl = new Bureaucrat("Sylvain", 10);
	Bureaucrat *BuHighLvl = new Bureaucrat("Antoine", 2);
	Bureaucrat *BuLowLvl = new Bureaucrat("Xavier", 149);
    PresidentialPardonForm *fPardon = new PresidentialPardonForm("Xavier Miel");
    RobotomyRequestForm *fRobot = new RobotomyRequestForm("R3B8");
    ShrubberyCreationForm *fTree = new ShrubberyCreationForm("Home");
    ShrubberyCreationForm *fTree2 = new ShrubberyCreationForm("Villa");
    std::cout << *fPardon << std::endl;
    std::cout << *fRobot << std::endl;
    std::cout << *fTree << std::endl;
	fPardon->beSigned(*BuMidHighLvl);
	fRobot->beSigned(*BuMidLvl);
	fTree->beSigned(*BuMidLvl);
	try
	{
		fPardon->execute(*BuMidHighLvl);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		fPardon->execute(*BuHighLvl);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		fRobot->execute(*BuLowLvl);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		fRobot->execute(*BuMidLvl);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		fTree->execute(*BuLowLvl);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    while (BuLowLvl->getGrade() > 137)
        BuLowLvl->incrGrade();
    fTree->execute(*BuLowLvl);
    BuMidHighLvl->executeForm(*fPardon);
    BuHighLvl->executeForm(*fTree2);
    BuLowLvl->executeForm(*fRobot);
	delete BuMidHighLvl;
	delete BuHighLvl;
	delete BuLowLvl;
    delete BuMidLvl;
    delete fPardon;
    delete fRobot;
    delete fTree;
    delete fTree2;
}

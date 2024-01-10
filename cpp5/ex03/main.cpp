/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/10 15:09:24 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"
#include "incs/AForm.hpp"
#include "incs/PresidentialPardonForm.hpp"
#include "incs/ShrubberyCreationForm.hpp"
#include "incs/RobotomyRequestForm.hpp"
#include "incs/Intern.hpp"
int main()
{
//    Bureaucrat *a = new Bureaucrat("Fifi", 42);
//	Bureaucrat *b = new Bureaucrat("Sylvain", 10);
//	Bureaucrat *c = new Bureaucrat("Antoine", 2);
//	Bureaucrat *d = new Bureaucrat("Xavier", 149);
//    PresidentialPardonForm *fPardon = new PresidentialPardonForm("Xavier Miel");
//    RobotomyRequestForm *fRobot = new RobotomyRequestForm("R3B8");
//    ShrubberyCreationForm *fTree = new ShrubberyCreationForm("Home");
//    ShrubberyCreationForm *fTree2 = new ShrubberyCreationForm("Villa");
//    std::cout << *fPardon << std::endl;
//    std::cout << *fRobot << std::endl;
//    std::cout << *fTree << std::endl;
//    fPardon->beSigned(*b);
//    fRobot->beSigned(*a);
//    fTree->beSigned(*a);
//    fPardon->execute(*b);
//    fPardon->execute(*c);
//    fRobot->execute(*d);
//    fRobot->execute(*a);
//    fTree->execute(*d);
//    while (d->getGrade() > 137)
//        d->incrGrade();
//    fTree->execute(*d);
//    b->executeForm(*fPardon);
//    c->executeForm(*fTree2);
//    d->executeForm(*fRobot);
//	delete b;
//	delete c;
//	delete d;
//    delete a;
//    delete fPardon;
//    delete fRobot;
//    delete fTree;
//    delete fTree2;
    Intern randomIntern;
    AForm*  shtJob;
    AForm*  shtJob2;
    AForm*  shtJob3;
    shtJob = randomIntern.makeForm("robotomy request", "Bender");
    shtJob2 = randomIntern.makeForm("presidential pardon", "Michelle");
    shtJob3 = randomIntern.makeForm("shrubbery creation", "Jardiland");
    std::cout << *shtJob << std::endl;
    std::cout << *shtJob2 << std::endl;
    std::cout << *shtJob3 << std::endl;

    delete shtJob;
    delete shtJob2;
    delete shtJob3;
}

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

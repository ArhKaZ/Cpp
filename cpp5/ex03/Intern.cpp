/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:34:06 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:44:16 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Intern.hpp"
#include "incs/PresidentialPardonForm.hpp"
#include "incs/RobotomyRequestForm.hpp"
#include "incs/ShrubberyCreationForm.hpp"
#include "incs/AForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formType, std::string target)
{
    int i;
    std::string Forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    for (i = 0; i < 3; i++)
    {
        if (Forms[i] == formType)
            break;
        if (i == 2)
        {
            i = 3;
            break;
        }
    }
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << formType << std::endl;
            return new RobotomyRequestForm(target);
        case 1:
            std::cout << "Intern creates " << formType << std::endl;
            return new PresidentialPardonForm(target);
        case 2:
            std::cout << "Intern creates " << formType << std::endl;
            return new ShrubberyCreationForm(target);
        case 3:
            std::cout << formType << " don't exist " << std::endl;
    }
    return (NULL);
}

Intern::Intern(const Intern &intern)
{
    (void)intern;
    return;
}

Intern& Intern::operator=(const Intern &intern)
{
    (void)intern;
    return *this;
}
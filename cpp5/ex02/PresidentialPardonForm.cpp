/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:22 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/09 16:47:49 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/PresidentialPardonForm.hpp"
#include "incs/AForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    this->setName(target);
    this->setGradeSign(25);
    this->setGradeExecute(5);
    this->setSign(false);
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    try
    {
        if (this->getGradeExecute() <= executor.getGrade()) {
            std::cout << this->getName() << " is pardonned by Zaphod Beeblebrox" << std::endl;
        }
        else
        {
            throw PardonException();
        }
    }
    catch (PardonException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

PresidentialPardonForm::~PresidentialPardonForm() {}
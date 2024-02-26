/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:22 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:29:42 by syluiset         ###   ########.fr       */
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
	if (executor.getGrade() <= this->getGradeExecute())
	{
		std::cout << this->getName() << " is pardonned by Zaphod Beeblebrox" << std::endl;
	}
	else
	{
		throw PardonException();
	}
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pdf)
{
    this->setName(pdf.getName());
    this->setSign(pdf.getSign());
    this->setGradeExecute(pdf.getGradeExecute());
    this->setGradeSign(pdf.getGradeSign());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &pdf)
{
    this->setName(pdf.getName());
    this->setSign(pdf.getSign());
    this->setGradeExecute(pdf.getGradeExecute());
    this->setGradeSign(pdf.getGradeSign());
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm()
{
    return;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    return;
}

const char* PresidentialPardonForm::PardonException::what() const throw()
{
	return "You are not allowed to Pardon";
}
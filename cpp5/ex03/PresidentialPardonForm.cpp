/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:22 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/29 15:46:20 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/PresidentialPardonForm.hpp"
#include "incs/AForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSign() == true && executor.getGrade() <= this->getGradeExecute())
	{
		std::cout << this->getName() << " is pardonned by Zaphod Beeblebrox" << std::endl;
	}
	else
	{
		throw PardonException();
	}
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pdf) : AForm(pdf.getName(), pdf.getGradeSign(), pdf.getGradeExecute())
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &pdf)
{
    this->setSign(pdf.getSign());
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
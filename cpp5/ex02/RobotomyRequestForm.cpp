/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:57:01 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/29 15:45:05 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int rand_nb;

	if (this->getSign() && executor.getGrade() <= this->getGradeExecute())
	{
		srand(time(NULL));
		std::cout << "*driiiiiiiiiiillll*" << std::endl;
		rand_nb = rand() % 2;
		if (rand_nb == 0)
		{
			std::cout << this->getName() << " has been robotomized successfully" << std::endl;
		}
		else
		{
			std::cout << this->getName() << " has failed to be robotomized" << std::endl;
		}
	}
	else
	{
		throw RobotomyException();
	}
}

RobotomyRequestForm::RobotomyRequestForm()
{
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : AForm(rrf.getName(), rrf.getGradeSign(), rrf.getGradeExecute())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    this->setSign(rrf.getSign());
    return *this;
}

const char* RobotomyRequestForm::RobotomyException::what() const throw()
{
	return "You are not allowed to Robotomy this form";
}
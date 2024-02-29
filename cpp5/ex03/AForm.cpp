/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:36:09 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/09 13:40:41 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/AForm.hpp"

AForm::AForm() : gradeSign(0), gradeExecute(0)
{
    return;
}

AForm::~AForm()
{
    return;
}

AForm::AForm(std::string name, unsigned int gradeSign, unsigned int gradeExecute) : name(name) ,gradeSign(gradeSign), gradeExecute(gradeExecute)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else
	{
		this->sign = false;
	}
}

AForm::AForm(const AForm &form) : name(form.name), gradeSign(form.gradeSign), gradeExecute(form.gradeExecute)
{
    this->sign = form.sign;
}

AForm &AForm::operator=(const AForm &form)
{
    this->sign = form.sign;
    return *this;
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (this->sign);
}

unsigned int AForm::getGradeExecute() const
{
	return (this->gradeExecute);
}

unsigned int AForm::getGradeSign() const
{
	return (this->gradeSign);
}

std::ostream& operator<<(std::ostream &op, AForm const &f)
{
	op << "Name : " << f.getName() << ", signed : " << f.getSign() << ", grade sign : " << f.getGradeSign() << " and grade execute : " << f.getGradeExecute();
	return (op);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
		this->sign = true;
	else
		throw GradeTooLowException();
}

void    AForm::setSign(bool value)
{
    this->sign = value;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade Form is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade Form is too low";
}
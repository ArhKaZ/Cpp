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

AForm::AForm()
{
	return;
}

AForm::~AForm()
{
	return;
}

AForm::AForm(const AForm &form)
{
	this->sign = form.sign;
	this->gradeSign = form.gradeSign;
	this->gradeExecute = form.gradeExecute;
	this->name = form.name;
}

AForm &AForm::operator=(const AForm &form)
{
	this->sign = form.sign;
	this->gradeSign = form.gradeSign;
	this->gradeExecute = form.gradeExecute;
	this->name = form.name;
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

void    AForm::setName(std::string name)
{
	this->name = name;
}

void    AForm::setGradeExecute(unsigned int lvl)
{
	this->gradeExecute = lvl;
}

void    AForm::setGradeSign(unsigned int lvl)
{
	this->gradeSign = lvl;
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
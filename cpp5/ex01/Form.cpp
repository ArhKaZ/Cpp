/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:36:09 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:14:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Form.hpp"

Form::Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute) : name(name) ,gradeSign(gradeSign), gradeExecute(gradeExecute)
{
	if (gradeSign > 150)
		throw GradeTooLowException();
	if (gradeSign < 1)
		throw GradeTooHighException();
	else
	{
		this->sign = false;
	}
}

Form::Form(const Form &form) : name(form.name), gradeSign(form.gradeSign), gradeExecute(form.gradeExecute)
{
    this->sign = form.sign;
}

Form &Form::operator=(const Form &form)
{
    this->sign = form.sign;
    return *this;
}

Form::Form() : gradeSign(0), gradeExecute(0)
{
    return;
}

Form::~Form()
{
    return;
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

const unsigned int Form::getGradeExecute() const
{
	return (this->gradeExecute);
}

const unsigned int Form::getGradeSign() const
{
	return (this->gradeSign);
}

std::ostream& operator<<(std::ostream &op, Form const &f)
{
	op << "Name : " << f.getName() << ", signed : " << f.getSign() << ", grade sign : " << f.getGradeSign() << " and grade execute : " << f.getGradeExecute() << std::endl;
	return (op);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
		this->sign = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade Form is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade Form is too low";
}
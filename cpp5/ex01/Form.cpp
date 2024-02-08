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

Form::Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute)
{
	try
	{
		if (gradeSign > 150)
			throw GradeTooLowException();
		if (gradeSign < 1)
			throw GradeTooHighException();
		else
		{
			this->name = name;
			this->gradeSign = gradeSign;
			this->gradeExecute = gradeExecute;
			this->sign = false;
		}
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Form::Form(const Form &form)
{
    this->sign = form.sign;
    this->gradeSign = form.gradeSign;
    this->gradeExecute = form.gradeExecute;
    this->name = form.name;
}

Form &Form::operator=(const Form &form)
{
    this->sign = form.sign;
    this->gradeSign = form.gradeSign;
    this->gradeExecute = form.gradeExecute;
    this->name = form.name;
    return *this;
}

Form::Form()
{
    return;
}

Form::~Form()
{
    return;
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

unsigned int Form::getGradeExecute() const
{
	return (this->gradeExecute);
}

unsigned int Form::getGradeSign() const
{
	return (this->gradeSign);
}

std::ostream& operator<<(std::ostream &op, Form const &f)
{
	op << "Name : " << f.getName() << ", signed : " << f.getSign() << ", grade sign : " << f.getGradeSign() << " and grade execute : " << f.getGradeExecute() << std::endl;
	return (op);
}

bool	Form::beSigned(Bureaucrat &b)
{
    try
    {
        if (b.getGrade() <= this->getGradeSign())
            this->sign = true;
	    else
		    throw GradeTooLowException();
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

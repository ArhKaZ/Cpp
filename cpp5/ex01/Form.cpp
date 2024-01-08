/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:36:09 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 16:07:42 by syluiset         ###   ########.fr       */
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

Form::~Form()
{

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
	op << "Name : " << f.getName() << ", signed : " << f.getSign() << ", grade sign : " << f.getGradeSign() << "and grade execute : " << f.getGradeExecute();
	return (op);
}

void	Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= this->getGradeSign())
		this->sign = true;
	else
		throw GradeTooLowException();
}

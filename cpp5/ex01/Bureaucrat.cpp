/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:23:57 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/09 13:44:45 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"
#include "incs/Form.hpp"

std::ostream &operator<<(std::ostream &op, Bureaucrat const &b)
{
	op << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (op);
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		else
		{
			this->_grade = grade;
			this->_name = name;
		}
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrGrade()
{
	try
	{
		if ((this->_grade - 1) < 1)
			throw GradeTooHighException();
		else
			this->_grade -= 1;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << this->_name << ' ' << e.what() << std::endl;
	}
}

void	Bureaucrat::downGrade()
{
	try
	{
		if ((this->_grade + 1) > 150)
			throw GradeTooLowException();
		else
			this->_grade += 1;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << this->_name << ' ' << e.what() << '\n';
	}

	this->_grade += 1;
}

void	Bureaucrat::signForm(AForm &f)
{
    if (!f.beSigned(*this))
	{
		std::cout << this->getName() << " couln't sign " << f.getName() << '\n';
	}
    else
	    std::cout << this->getName() << " signed " << f.getName() << std::endl;
}

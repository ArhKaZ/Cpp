/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:23:57 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 14:27:43 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"

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
			this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	this->_name = name;
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

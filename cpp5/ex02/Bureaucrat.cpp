/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:23:57 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/29 15:43:09 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"
#include "incs/AForm.hpp"

std::ostream &operator<<(std::ostream &op, Bureaucrat const &b)
{
	op << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (op);
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    return;
}

Bureaucrat::Bureaucrat()
{
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name)
{
    this->_grade = bureaucrat._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    this->_grade = bureaucrat._grade;
    return *this;
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrGrade()
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::downGrade()
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couln't sign " << f.getName() << " because " << e.what() << '\n';
	}
}

void    Bureaucrat::executeForm(AForm const &form)
{
    if (form.getSign() == true && this->getGrade() <= form.getGradeExecute())
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    else
    {
        std::cout << this->getName() << " can't execute " << form.getName() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:53:04 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/29 15:46:52 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    int spaces = 20 - 1;
    int stars = 1;
	if (this->getSign() && executor.getGrade() <= this->getGradeExecute())
	{
		std::ofstream ofs;
		std::string filename = this->getName() + "_shrubbery";
		ofs.open (filename.c_str(), std::ofstream::out);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < spaces; j++)
			{
				ofs << " ";
			}
			for (int j = 0; j < stars; j++)
			{
				ofs << "*";
			}
			ofs << std::endl;
			spaces--;
			stars += 2;
		}
		for (int i = 0; i < 20 - 1; i++)
		{
			ofs << " ";
		}
		ofs << "*" << std::endl;
		ofs.close();
	}
	else
		throw ShrubberyException();
}

ShrubberyCreationForm::ShrubberyCreationForm()
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) : AForm(scf.getName(), scf.getGradeSign(), scf.getGradeExecute())
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
    this->setSign(scf.getSign());
    return *this;
}

const char* ShrubberyCreationForm::ShrubberyException::what() const throw()
{
	return "You are not allowed to get a shrubbery";
}
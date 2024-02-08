/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:53:04 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/10 10:58:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->setName(target);
    this->setGradeSign(145);
    this->setGradeExecute(137);
    this->setSign(false);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    int spaces = 20 - 1;
    int stars = 1;
    try
    {
        if (executor.getGrade() <= this->getGradeExecute())
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
    catch (ShrubberyException &e)
    {
         std::cout << e.what() << std::endl;
    }
}

ShrubberyCreationForm::ShrubberyCreationForm()
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
{
    this->setName(scf.getName());
    this->setSign(scf.getSign());
    this->setGradeExecute(scf.getGradeExecute());
    this->setGradeSign(scf.getGradeSign());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
    this->setName(scf.getName());
    this->setSign(scf.getSign());
    this->setGradeExecute(scf.getGradeExecute());
    this->setGradeSign(scf.getGradeSign());
    return *this;
}
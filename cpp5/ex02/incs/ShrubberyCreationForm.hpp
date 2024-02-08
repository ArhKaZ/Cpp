/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:51:17 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:29:43 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
    class ShrubberyException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "You are not allowed to get a shrubbery";
        }
    };
public :
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const & executor) const;
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &scf);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &scf);
};

#endif

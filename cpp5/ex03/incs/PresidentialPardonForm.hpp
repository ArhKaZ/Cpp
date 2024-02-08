/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:01:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:36:59 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    class PardonException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "You are not allowed to Pardon";
        }
    };
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &pdf);
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    void    execute(Bureaucrat const & executor) const;
    PresidentialPardonForm& operator=(const PresidentialPardonForm &pdf);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:01:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/09 14:41:26 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : AForm
{
    class PardonException : std::exception
    {
    public:
        std::string what()
        {
            return "You are not allowed to Pardon";
        }
    };
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    void    execute(Bureaucrat const & executor) const;
};

#endif
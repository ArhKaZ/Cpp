/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:57:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/09 16:47:49 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <stdlib.h>
class RobotomyRequestForm : AForm
{
    class RobotomyException : std::exception
    {
    public:
        std::string what()
        {
            return "You are not allowed to Robotomy this form";
        }
    };
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    void    execute(Bureaucrat const & executor) const;
};

#endif
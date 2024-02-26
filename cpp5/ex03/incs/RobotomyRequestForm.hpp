/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:57:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:36:59 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <stdlib.h>
class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &rrf);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &rrf);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	void    execute(Bureaucrat const & executor) const;
	class RobotomyException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
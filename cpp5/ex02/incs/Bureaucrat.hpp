/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:00 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:30:26 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		std::string _name;
		unsigned int _grade;
	public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat(std::string name, unsigned int grade);
        ~Bureaucrat();
        void	signForm(AForm &f);
        std::string getName() const;
        unsigned int getGrade() const;
        void	incrGrade();
        void	downGrade();
        Bureaucrat& operator = (const Bureaucrat &bureaucrat);
        void    executeForm(AForm const & form);
		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &op, Bureaucrat const &b);

#endif

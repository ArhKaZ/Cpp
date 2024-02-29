/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:00 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:06:47 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade;
	public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();
		const std::string getName() const;
		unsigned int getGrade() const;
		void	incrGrade();
		void	downGrade();
        Bureaucrat& operator = (const Bureaucrat &bureaucrat);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:00 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/09 09:43:05 by syluiset         ###   ########.fr       */
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
	class GradeTooHighException : public std::exception
	{
		public:
		std::string what()
		{
			return "Grade is too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		std::string what()
		{
			return "Grade is too low";
		}
	};


	private:
		std::string _name;
		unsigned int _grade;
	public:
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();
		void	signForm(AForm &f);
		std::string getName() const;
		unsigned int getGrade() const;
		void	incrGrade();
		void	downGrade();

};

std::ostream &operator<<(std::ostream &op, Bureaucrat const &b);

#endif

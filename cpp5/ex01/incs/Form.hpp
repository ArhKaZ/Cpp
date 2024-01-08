/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:49 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 16:07:49 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
	class GradeTooHighException : public std::exception
	{
		public:
		std::string what()
		{
			return "Grade Form is too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		std::string what()
		{
			return "Grade Form is too low";
		}
	};

	private :
		std::string name;
		bool sign;
		unsigned int gradeSign;
		unsigned int gradeExecute;
	public :
		Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute);
		~Form();
		std::string getName() const;
		bool getSign() const;
		unsigned int getGradeSign() const;
		unsigned int getGradeExecute() const;
		void beSigned(Bureaucrat b);
};

std::ostream& operator<<(std::ostream &op, Form const &f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:49 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 14:53:30 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private :
		const std::string name;
		bool sign;
		const unsigned int gradeSign;
		const unsigned int gradeExecute;
	public :
        Form();
        Form(const Form &form);
		Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute);
		~Form();
		const std::string getName() const;
		bool getSign() const;
		const unsigned int getGradeSign() const;
		const unsigned int getGradeExecute() const;
		void beSigned(Bureaucrat &b);
        Form &operator = (const Form &form);
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

std::ostream& operator<<(std::ostream &op, Form const &f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:49 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:33:49 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Grade Form is too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
        virtual const char* what() const throw()
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
        AForm();
        AForm(const AForm &form);
		virtual ~AForm();
        std::string getName() const;
		bool getSign() const;
		unsigned int getGradeSign() const;
		unsigned int getGradeExecute() const;
        bool beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void    setName(std::string name);
        void    setGradeSign(unsigned int lvl);
        void    setGradeExecute(unsigned int lvl);
        void    setSign(bool value);
        AForm &operator = (const AForm &form);
};

std::ostream& operator<<(std::ostream &op, AForm const &f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:04:56 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/29 12:10:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/RPN.hpp"

RPN::RPN() {}

RPN::~RPN()
{
	while (!this->calc.empty())
	{
		calc.pop();
	}
}

RPN::RPN(const RPN &rpn)
{
	this->calc = rpn.calc;
}

RPN::RPN(const std::string &s)
{
	int nb1;
	int nb2;
	char ope;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '.' || s[i] == '(' || s[i] == ')')
		{
			std::cout << "ERROR" << std::endl;
			return ;
		}
		else if (s[i] >= 48 && s[i] <= 57)
		{
			this->calc.push(atoi(&s[i]));
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
		{
			if (this->calc.size() != 2)
			{
				std::cout << "Error with inputs" << std::endl;
				return ;
			}
			ope = s[i];
			i++;
			nb2 = this->calc.top();
			this->calc.pop();
			nb1 = this->calc.top();
			this->calc.pop();
			try
			{
				this->calc.push(do_calc(ope, nb1, nb2));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				exit(EXIT_FAILURE);
			}
		}
		else if (s[i] != ' ')
		{
			std::cout << "Error with inputs" << std::endl;
			return ;
		}
	}
	if (this->calc.size() > 1)
	{
		std::cout << "Error with you'r inputs" << std::endl;
	}
	else
		std::cout << this->calc.top();
}

RPN &RPN::operator=(const RPN &rpn)
{
	this->calc = rpn.calc;
	return *this;
}

int RPN::do_calc(char ope, int nb1, int nb2)
{
	if (ope == '+')
		return (nb1 + nb2);
	if (ope == '-')
		return (nb1 - nb2);
	if (ope == '*')
		return (nb1 * nb2);
	if (ope == '/')
	{
		if (nb2 == 0)
		{
			throw DivByZero();
		}
		return (nb1 / nb2);
	}
	return (0);
}

const char* RPN::DivByZero::what() const throw()
{
	return "You can't divide by 0";
}
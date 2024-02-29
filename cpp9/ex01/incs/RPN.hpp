/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:05:14 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/29 12:08:50 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
# include <stack>
# include <string>
# include <cstdlib>
# include <iostream>
class RPN
{
public:
	RPN();
	~RPN();
	RPN(const std::string &s);
	RPN(const RPN &rpn);
	RPN& operator=(const RPN &rpn);
	class DivByZero : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
private:
	int do_calc(char ope, int nb1, int nb2);
	std::stack<int> calc;
};


#endif
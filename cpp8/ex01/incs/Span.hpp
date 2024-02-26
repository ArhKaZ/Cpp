/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:40:26 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/20 20:22:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
# include <iostream>
# include <list>
# include <exception>
# include <time.h>
# include <stdlib.h>
class Span
{
public:
	std::list<int> _lst;
	Span();
	~Span();
	Span(unsigned int N);
	Span(const Span &s);
	Span& operator=(const Span &s);
	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();
	void addSeveralNumber(std::list<int> lst, unsigned int begin, unsigned int end);
	unsigned int getMax();
	class AddToMuchNb : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class ListNonUsable : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
private:
	unsigned int _max;
};


#endif
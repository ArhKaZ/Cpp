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
class Span
{
public:
	Span();
	~Span();
	Span(unsigned int N);
	Span(const Span &s);
	Span& operator=(const Span &s);
	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();
	void addSeveralNumber(Span &sp, unsigned int begin, unsigned int end);
	std::list<int> getList();
private:
	std::list<int> _lst;
	unsigned int _max;
};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:47:10 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/20 20:26:15 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Span.hpp"

Span::Span(){ return ;}

Span::~Span(){ return ;}

Span::Span(unsigned int N) : _max(N)
{
	return;
}

Span::Span(const Span &s) : _max(s._max)
{
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator end = s._lst.end();

	for (it = s._lst.begin(); it != end; it++)
	{
		this->_lst.push_back(*it);
	}
}

Span& Span::operator=(const Span &s)
{
	this->_max = s._max;
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator end = s._lst.end();

	for (it = s._lst.begin(); it != end; it++)
	{
		this->_lst.push_back(*it);
	}
	return *this;
}

void Span::addNumber(int nb)
{
	if (this->_lst.size() == this->_max)
		throw std::exception();
	else
	{
		this->_lst.push_back(nb);
	}
}

int Span::longestSpan()
{
	if (this->_lst.size() == 0 || this->_lst.size() == 1)
		throw std::exception();
	else
	{
		int dist = 0;
		int temp = 0;
		std::list<int>::iterator it_now;
		std::list<int>::iterator it_next = this->_lst.begin()+1;
		std::list<int>::iterator it_end = this->_lst.end();

		for(it_now = this->_lst.begin(); it_next != it_end; it_now++, it_next++)
		{
			temp = *it_next - *it_now;
			if (temp > dist)
				dist = temp;
		}
		return (dist);
	}
	return (0);
}

int Span::shortestSpan()
{
	if (this->_lst.size() == 0 || this->_lst.size() == 1)
		throw std::exception();
	else
	{
		int dist = 0;
		int temp = 0;
		std::list<int>::iterator it_now;
		std::list<int>::iterator it_next;
		std::list<int>::iterator it_end = this->_lst.end();

		for(it_now = this->_lst.begin(), it_next = it_now + 1; it_next != it_end; it_now++, it_next++)
		{
			temp = *it_next - *it_now;
			if (temp < dist)
				dist = temp;
		}
		return (dist);
	}
	return (0);
}

void Span::addSeveralNumber(Span &sp, unsigned int begin, unsigned int end)
{
	std::list<int>::iterator it = sp.getList().begin() + begin;
	std::list<int>::iterator itEnd = sp.getList().end() - (sp.getList().size() - end);

	this->_lst.assign(it, itEnd);
}

std::list<int> Span::getList()
{
	return this->_lst;
}
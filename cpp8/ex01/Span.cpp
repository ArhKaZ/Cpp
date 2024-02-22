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
		throw AddToMuchNb();
	else
	{
		this->_lst.push_back(nb);
	}
}

int Span::longestSpan()
{
    if (this->_lst.size() == 0 || this->_lst.size() == 1)
    {
        throw ListNonUsable();
    }
    else
    {
        unsigned int dist = 0;
        unsigned int temp = 0;
        std::list<int>::iterator it_now;
        std::list<int>::iterator it_next = ++this->_lst.begin();
        std::list<int>::iterator it_end = this->_lst.end();

        for(it_now = this->_lst.begin(); it_next != it_end; it_now++)
        {
            if (*it_next < *it_now)
            {
                temp = *it_now - *it_next;
            }
            else
            {
                temp = *it_next - *it_now;
            }
            if (temp > dist || dist == 0)
                dist = temp;
            it_next++;
        }
        return (dist);
    }
}

int Span::shortestSpan()
{
    if (this->_lst.size() == 0 || this->_lst.size() == 1)
    {
        throw ListNonUsable();
    }
    else
    {
        unsigned int dist = 0;
        unsigned int temp = 0;
        std::list<int>::iterator it_now;
        std::list<int>::iterator it_next = ++this->_lst.begin();
        std::list<int>::iterator it_end = this->_lst.end();

        for(it_now = this->_lst.begin(); it_next != it_end; it_now++)
        {
            if (*it_next < *it_now)
            {
                temp = *it_now - *it_next;
            }
            else
            {
                temp = *it_next - *it_now;
            }
            if (temp < dist || dist == 0)
                dist = temp;
            it_next++;
        }
        return (dist);
    }
}

void Span::addSeveralNumber(std::list<int> lst, unsigned int begin, unsigned int end)
{
	unsigned int newSize = (this->_lst.size() - begin) - (this->_lst.size() - end);
	if (newSize > this->_max)
		throw AddToMuchNb();
	std::list<int>::iterator it = lst.begin();
    for(unsigned int i = 0; i < begin; i++)
    {
        it++;
    }
	std::list<int>::iterator itEnd = lst.end();
    for(unsigned int i = 0; i < lst.size() - end; i++)
    {
        end--;
    }
	this->_lst.insert(this->_lst.end(), it, itEnd);
}

unsigned int Span::getMax()
{
	return this->_max;
}
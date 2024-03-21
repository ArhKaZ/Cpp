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
#include <limits>
#include <algorithm>

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
	if (this == &s)
		return *this;
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
	int min = 0;
	int max = 0;
	int dist = 0;
    if (this->_lst.size() == 0 || this->_lst.size() == 1)
    {
        throw ListNonUsable();
    }
    else
    {
        min = *std::min_element(this->_lst.begin(), this->_lst.end());
        max = *std::max_element(this->_lst.begin(), this->_lst.end());
		dist = max - min;
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
        unsigned int dist = std::numeric_limits<unsigned int>::max();
        unsigned int temp = 0;
        std::list<int>::iterator it_now;
        std::list<int>::iterator it_next = ++this->_lst.begin();
        std::list<int>::iterator it_end = this->_lst.end();
		this->_lst.sort();

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
            if (temp < dist)
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

std::list<int> Span::getList()
{
	return this->_lst;
}

const char* Span::AddToMuchNb::what() const throw()
{
	return "Add more number compare to the max of the list";
}

const char* Span::ListNonUsable::what() const throw()
{
	return "List as none or only one number !";
}
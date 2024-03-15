/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:55:12 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/16 17:14:38 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_ARRAY_HPP
#define CPP_ARRAY_HPP
#include "iostream"

template<typename T>
class Array
{
public:
	Array(){}
	~Array()
	{
		delete[] _tab;
	}
	Array(unsigned int n) : _size(n)
	{
		this->_tab = new T[n]();
		return ;
	}
	Array(const Array& Array)
	{
		this->_tab = new T[Array._size];
		for(unsigned int i = 0; i < Array._size; i++)
		{
			this->_tab[i] = Array._tab[i];
		}
	}
	Array& operator=(const Array & Array)
	{
		for(unsigned int i = 0; i < Array._size; i++)
		{
			this->_tab[i] = Array._tab[i];
		}
		return *this;
	}
	T& operator[](int x)
	{
			if (x < 0 || static_cast<size_t>(x) >= this->_size)
				throw std::exception();
			else
				return this->_tab[x];
	}
	size_t size()
	{
		return (_size);
	}
private:
	T *_tab;
	unsigned int _size;
};

#endif

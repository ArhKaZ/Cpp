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

template<typename T>
class Array
{
public:
	Array(){}
	~Array(){}
	Array(unsigned int n)
	{
		this->_tab = new T[n];
		return ;
	}
	Array(T const tab[])
	{
		size_t size = sizeof(*tab) / sizeof(tab[0]);
		for(int i = 0; i < size; i++)
		{
			this->_tab[i] = tab[i];
		}
	}
	T* operator=(T const tab[])
	{
		size_t size = sizeof(*tab) / sizeof(tab[0]);
		for(int i = 0; i < size; i++)
		{
			this->_tab[i] = tab[i];
		}
		return *this;
	}
	T& operator[](int x)
	{
			if (x < 0 || static_cast<size_t>(x) > sizeof(*this->_tab) / sizeof(this->_tab[0]))
				throw std::exception();
			else
				return this->_tab[x];
	}
	size_t size()
	{
		return (sizeof(*this->_tab) / sizeof(this->_tab[0]));
	}
private:
	T *_tab;
};

#endif

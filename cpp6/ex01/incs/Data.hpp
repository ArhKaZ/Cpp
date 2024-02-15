/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:38:13 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 14:47:29 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
	unsigned long _value;
public:
	Data();
	Data(unsigned long value);
	Data(const Data &Data);
	Data& operator=(const Data &Data);
	~Data();
	unsigned long get_value();
};

#endif
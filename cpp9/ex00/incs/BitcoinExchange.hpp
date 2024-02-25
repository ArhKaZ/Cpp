/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:09:24 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/25 20:48:26 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &be);
	BitcoinExchange &operator=(const BitcoinExchange &be);
	void get_info_from_files(std::string path);
	void displayBTCExchange();
	typedef std::map<std::string, int>::iterator mIterator;
private:
	std::map<std::string, int> inputs;
	std::map<std::string, float> base;
	float calc_exchange(mIterator &it);
};

#include <iostream>

#endif
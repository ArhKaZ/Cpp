/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:11:00 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/25 21:42:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/BitcoinExchange.hpp"
std::map<std::string, float> get_info_float(std::string path);

BitcoinExchange::BitcoinExchange()
{
	this->base = get_info_float("./data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
	this->base.erase(base.begin(), base.end());
	this->inputs.erase(inputs.begin(), inputs.end());
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &be)
{
	this->base = be.base;
	this->inputs = be.inputs;
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &be)
{
	this->base = be.base;
	this->inputs = be.inputs;
}

bool verif_date_string(std::string s)
{
	if (s[4] != '-' || s[7] != '-')
		return false;
	for (int i = 0; i < 4; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return false;
	}
	for (int i = 5; i < 7; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return false;
	}
	for (int i = 8; i < 10; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return false;
	}
	return true;
}

bool leap_year(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

int* get_date_ints(std::string s)
{
	int date[3] = {0, 0, 0};
	std::string temp;

	temp = s.substr(0, 4);
	date[0] = atoi(temp.c_str());
	temp = s.substr(5, 2);
	date[1] = atoi(temp.c_str());
	temp = s.substr(8, 2);
	date[2] = atoi(temp.c_str());
	return date;
}

bool verif_date_number(std::string s)
{
	int* date = get_date_ints(s); //! Delete ?

	if (date[0] < 0 || date[1] <= 0 || date[1] > 12 || date[2] < 0)
		return (false);
	if (date[1] == 2)
	{
		if (leap_year(date[0]))
		{
			if (date[2] > 29)
				return (false);
		}
		else
		{
			if (date[2] > 28)
				return (false);
		}
	}
	else
	{
		if (date[1] % 2 == 0)
		{
			if (date[2] > 30)
				return (false);
		}
		else
		{
			if (date[2] > 31)
				return (false);
		}
	}
	return (false);
}

std::map<std::string, float> get_info_float(std::string path)
{
	std::string line;
	std::ifstream myfile;
	char tmp;
	std::map<std::string, float> map;
	std::string date;
	std::string value;

	myfile.open(path.c_str(), std::ifstream::in);
	while (myfile.get(tmp))
	{
		if (tmp == '\n')
		{
			date = line.substr(0, line.find(","));
			value = line.substr(line.find(",") + 1, (line.size() - line.find(",")) - 1);
			map.insert(std::pair<std::string, float>(date, static_cast<float>(atof(value.c_str()))));
			date.erase(date.begin(), date.end());
			value.erase(date.begin(), date.end());
			line.erase(line.begin(), line.end());
		}
		else
		{
			line.push_back(tmp);
		}
	}
	return (map);
}

float BitcoinExchange::calc_exchange(mIterator &it) //! Utiliser std::pair !!
{
	std::map<std::string, float>::iterator itF;
	std::map<std::string, float>::iterator iteF = this->base.end();
	int* dateInput = get_date_ints(*it.at());
	int* dateBase;
	for (itF = this->base.begin(); itF != iteF; itF++)
	{
		dateBase = 
	}
}

void BitcoinExchange::displayBTCExchange()
{
	mIterator it;
	mIterator ite = this->inputs.end();
	
	for (it = this->inputs.begin(); it != ite; it++)
	{
		
	}
}

void BitcoinExchange::get_info_from_files(std::string path)
{
	std::string line;
	std::ifstream myfile;
	char tmp;
	std::map<std::string, int> map;
	std::string date;
	std::string value;

	try
	{
		myfile.open(path.c_str(), std::ifstream::in);
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR : " << e.what() << '\n';
		return;
	}
	while (myfile.get(tmp))
	{
		if (tmp == '\n')
		{
			if (!verif_date_string(line) || !verif_date_number(line))
			{
				std::cerr << "ERROR: bad input => " << line;
				line.erase(line.begin(), line.end());
				map.erase(map.begin(), map.end());
				return;
			}
			date = line.substr(0, line.find("|") - 1);
			value = line.substr(line.find("|") + 2, (line.size() - line.find(",")) - 1);
			map.insert(std::pair<std::string, int>(date, atoi(value.c_str())));
			date.erase(date.begin(), date.end());
			value.erase(date.begin(), date.end());
			line.erase(line.begin(), line.end());
		}
		else
		{
			line.push_back(tmp);
		}
	}
	this->inputs = map;
	myfile.close();
}
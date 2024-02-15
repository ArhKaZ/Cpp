/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:18:42 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 14:59:42 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/AScalarConverter.hpp"

AScalarConverter::AScalarConverter() {}

AScalarConverter::~AScalarConverter() {}

int	nb_dot_in_string(std::string s)
{
	int nb_dot = 0;

	for (unsigned long i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			nb_dot++;
	}
	return (nb_dot);
}

int nb_f_in_string(std::string s)
{
	int nb_f = 0;

	for (unsigned long i = 0; i < s.length(); i++)
	{
		if (s[i] == 'f')
			nb_f++;
	}
	return (nb_f);
}

int	check_inf_and_nan(std::string s)
{
	if (s.compare("-inff") == 0 || s.compare("-inf") == 0)
		return 1;
	else if (s.compare("+inff") == 0 || s.compare("+inf") == 0)
		return 2;
	else if (s.compare("nan") == 0 || s.compare("nanf") == 0)
		return 3;
	return 0;
}

void	display_inf_and_nan(std::string s, std::string type)
{
	int ret = 0;

	ret = check_inf_and_nan(s);
	if (ret == 1)
	{
		if (type.compare("float") == 0)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	if (ret == 2)
	{
		if (type.compare("float") == 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "+inf" << std::endl;
	}
	if (ret == 3)
	{
		if (type.compare("float") == 0)
			std::cout << "nanf" << std::endl;
		else
			std::cout << "nan" << std::endl;
	}
}

void    display_char(std::string s, bool is_physic, int nb_dot)
{
    char char_display;
	double dbl = 0.0;
    long int tmp = 0;

	std::cout << "char: ";
    if (is_physic)
	{
		std::cout << "Impossible" << std::endl;
		return;
	}
	if (nb_dot == 0)
	{
		tmp = strtol(s.c_str(), NULL, 10);
		char_display = static_cast<char>(tmp);
	}
	else
	{
		dbl = atof(s.c_str());
		char_display = static_cast<char>(dbl);
	}
	if (char_display <= 31 || char_display >= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_display << std::endl;
}

void display_int(std::string s, bool is_physic, int nb_dot)
{
	int int_dislay = 0;
    long int tmp = 0;
	double double_di = 0.0;
	std::cout << "int: ";
	if (is_physic)
	{
		std::cout << "Impossible" << std::endl;
		return ;
	}
	if (nb_dot == 0)
	{
		tmp = strtol(s.c_str(), NULL, 10);
		int_dislay = static_cast<int>(tmp);
	}
	else
	{
		double_di = atof(s.c_str());
		int_dislay = static_cast<int>(double_di);
	}
	std::cout << int_dislay << std::endl;
}

void    display_float(std::string s, bool is_physic, int nb_dot)
{
	long int tmp = 0;
    float float_display = 0.0f;
    double double_display = 0.0;
	int test = 0;
    std::cout << "float: ";
    if (is_physic)
		return (display_inf_and_nan(s, "float"));
	if (nb_dot == 0)
	{
		tmp = strtol(s.c_str(), NULL, 10);
		float_display = static_cast<float>(tmp);
	}
	else
	{
		double_display = std::atof(s.c_str());
		float_display = static_cast<float>(double_display);
	}
	std::cout << float_display;
	test = static_cast<int>(float_display);
	if (float_display - test == 0)
		std::cout << ".0f";
	std::cout << std::endl;
}

void    display_double(std::string s, bool is_physic, int nb_dot)
{
	int test = 0;
    double double_display = 0.0;
	long int tmp = 0;
    std::cout << "double: ";
	if (is_physic)
		return (display_inf_and_nan(s, "double"));
	if (nb_dot == 0)
	{
		tmp = std::strtol(s.c_str(), NULL, 10);
		double_display = static_cast<double>(tmp);
	}
	else
		double_display = std::atof(s.c_str());
	std::cout << double_display;
	test = static_cast<int>(double_display);
	if (double_display - test == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void AScalarConverter::convert(std::string s)
{
	//? Si un point alors faire atof, sinon fait strtol
	bool is_physic = false;
	int nb_dot = 0;

	if (check_inf_and_nan(s) != 0)
		is_physic = true;
	else
		nb_dot = nb_dot_in_string(s);
	if (nb_dot > 1)
	{
		std::cout << "Too much dot on the value" << std::endl;
		return ;
	}
    display_char(s, is_physic, nb_dot);
    display_int(s, is_physic, nb_dot);
    display_float(s, is_physic, nb_dot);
    display_double(s, is_physic, nb_dot);
}

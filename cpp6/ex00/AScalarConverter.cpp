/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:18:42 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/12 14:42:37 by syluiset         ###   ########.fr       */
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

void    display_char(std::string s, int type)
{
    char char_display;
    long int tmp;

    if (type != 1)
    {
        tmp = std::strtol(s.c_str(), NULL, 10);
        char_display = static_cast<int>(tmp);
    }
    else
        char_display = s[0];
    std::cout << "char: ";
    if (char_display >= 32 && char_display <= 126)
    {
        std::cout << char_display << std::endl;
        return ;
    }
    else
    {
        std::cout << "Non displayable" << std::endl;
        return ;
    }
}

void display_int(std::string s, int type)
{
    int int_display;
    long int tmp;

    (void)type;
    tmp = std::strtol(s.c_str(), NULL, 10);
    int_display = static_cast<int>(tmp);
    std::cout << int_display << std::endl;
}

void    display_float(std::string s, int type)
{
    float float_display;
    double double_display;
    (void) type;
    if (s.compare("-inff") == 0)
    {
        std::cout << "-inff" << std::endl;
        return ;
    }
    else if (s.compare("+inff") == 0)
    {
        std::cout << "+inff" << std::endl;
        return ;
    }
    else
    {
        double_display = std::atof(s.c_str());
        float_display = static_cast<float>(double_display);
        std::cout << float_display << std::endl;
        return ;
    }
}

void    display_double(std::string s, int type)
{
    double double_display;

    (void)type;
    if (s.compare("-inf") == 0)
    {
        std::cout << "-inf" << std::endl;
        return ;
    }
    else if (s.compare("+inf") == 0)
    {
        std::cout << "+inf" << std::endl;
        return ;
    }
    else if (s.compare("nan") == 0)
    {
        std::cout << "nan" << std::endl;
        return ;
    }
    else
    {
        double_display = std::atof(s.c_str());
        std::cout << double_display << std::endl;
        return ;
    }
}

void AScalarConverter::convert(std::string s)
{
	int	nb_dot;
    int type;

    type = 0;
    if ((s[0] >= 65 && s[0] <= 90 )|| (s[0] >= 97 && s[0] <= 122))
        type = 1;
    if ((s[0] >= 48 && s[0] <= 57) || (s[0] == '-' && s[1] >= 48 && s[1] <= 57) || (s[0] == '+' && s[1] >= 48 && s[1] <= 57))
    {
        nb_dot = nb_dot_in_string(s);
        if (nb_dot > 1)
        {
            std::cout << "error with multiple dot" << std::endl;
            return ;
        }
        else if (nb_dot == 0)
            type = 2;
        else if (nb_dot == 1)
        {
            if (s.find("f") > 0)
            {
                type = 3;
            }
            else
            {
                type = 4;
            }
        }
    }
    display_char(s, type);
    display_int(s, type);
    display_float(s, type);
    display_double(s, type);
	std::cout << "error with the string it have to convert." << std::endl;
}

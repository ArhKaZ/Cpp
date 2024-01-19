/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:18:42 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/19 15:15:32 by syluiset         ###   ########.fr       */
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

void AScalarConverter::convert(std::string s)
{
    char char_display;
	long int tmp;
    int int_display;
    float float_display;
    double double_display;
	int	nb_dot;

    if (s.length() == 1)
    {
        if (s[0] >= 32 && s[0] <= 126)
        {
            char_display = s[0];
            std::cout << char_display << std::endl;
			return ;
        }
		else
		{
			std::cout << "Character non displayable" << std::endl;
			return ;
		}
    }
	else
	{
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
		else if (s.compare("-inff") == 0)
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
			if ((s[0] >= 48 && s[0] <= 57) || (s[0] == '-' && s[1] >= 48 && s[1] <= 57) || (s[0] == '+' && s[1] >= 48 && s[1] <= 57))
			{
				nb_dot = nb_dot_in_string(s);
				if (nb_dot > 1)
				{
					std::cout << "error with multiple dot" << std::endl;
					return ;
				}
				if (nb_dot == 0)
				{
					tmp = std::strtol(s.c_str(), NULL, 10);
					int_display = static_cast<int>(tmp);
					std::cout << int_display << std::endl;
					return ;
				}
				if (nb_dot == 1)
				{
					if (s.find("f") > 0)
					{
						double_display = std::atof(s.c_str());
						float_display = static_cast<float>(double_display);
						std::cout << float_display << std::endl;
						return ;
					}
					else
					{
						double_display = std::atof(s.c_str());
						std::cout << double_display << std::endl;
						return ;
					}
				}
			}
		}
	}
	std::cout << "error with the string it have to convert." << std::endl;
}
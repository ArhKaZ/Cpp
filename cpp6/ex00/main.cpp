/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:23:11 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/18 14:39:02 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/AScalarConverter.hpp"

int main()
{
    AScalarConverter::convert("c");
    AScalarConverter::convert("*");
    AScalarConverter::convert("-20241");
    AScalarConverter::convert("-5412.23f");
    AScalarConverter::convert("-5412.23");
	AScalarConverter::convert("-inff");
	AScalarConverter::convert("-inf");
	AScalarConverter::convert("+inff");
	AScalarConverter::convert("+inffffff");
	AScalarConverter::convert("+inf");
	AScalarConverter::convert("nan");
	AScalarConverter::convert("COCUWDQWDQ");
}
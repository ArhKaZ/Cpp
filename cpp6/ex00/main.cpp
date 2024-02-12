/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:23:11 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/12 14:33:36 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/AScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        AScalarConverter::convert(argv[1]);
    return (0);
}
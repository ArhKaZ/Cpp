/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:21:36 by syluiset          #+#    #+#             */
/*   Updated: 2023/11/27 14:14:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/fSed.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        fSed(argv);
    }
    else
    {
        std::cout << "Not good arguments" << std::endl;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:55:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/11/27 17:16:33 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    
    if (argc == 2)
    {
        harl.complain(argv[1]);
    }
    return (0);
}
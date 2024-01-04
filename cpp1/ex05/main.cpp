/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:55:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/11/27 16:14:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Harl.hpp"

int main()
{
    std::string level;
    Harl harl;
    
    while (1)
    {
        std::cout << "Enter a level of complaning, in CAPS please" << std::endl;
        std::cin >> level;
        if (level.compare("exit") == 0)
            break ;
        harl.complain(level);
    }
    return (0);
}
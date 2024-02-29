/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:04:23 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/29 12:04:52 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "incs/RPN.hpp"

int main(int argc, char **argv)
{ // Faire directement les operations lors qu'on stock (utiliser stack)
	if (argc == 2)
	{
		RPN myRpn(argv[1]);
	}
	else
	{
		std::cout << "need only one argument." << std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:10:57 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/25 20:43:04 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::string line;
	std::string date;
	std::string value;

	if (argc == 2)
	{
		BitcoinExchange be;

		be.get_info_from_files(argv[1]);
	}
	else
	{
		std::cout << "Need an argument." << std::endl;
	}
}
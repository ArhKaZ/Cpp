/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fSed.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:06:47 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/20 00:29:52 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/fSed.hpp"

void    fSed(char **argv)
{
    std::string line;
    std::string filename;
    std::string filename_out;
    std::size_t found_s;
    std::string s1;
    std::string s2;

    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    std::ifstream filein(filename.c_str());
    if (filein.is_open())
    {
        if (!std::getline(filein, line))
        {
            std::cout << "The file is empty" << std::endl;
			filein.close();
            exit(1);
        }
        filename_out = filename + ".replace";
        std::ofstream fileout(filename_out.c_str());
        if (fileout.is_open())
        {
            while (std::getline(filein, line)) 
            {
                found_s = 0;
                found_s = line.find(s1);
                if (found_s != std::string::npos)
                {
                    line.erase(found_s, s1.length());
                    line.insert(found_s, s2);
                }
                fileout << line << std::endl;
            }
            fileout.close();
        }
        else 
        {
            std::cerr << "Can't create or open outfile.\n";
        }
        filein.close();
    }
    else {
        std::cerr << "Can't open the infile\n";
    }
}
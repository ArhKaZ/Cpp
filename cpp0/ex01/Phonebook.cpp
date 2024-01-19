/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:16:07 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/19 12:20:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <iostream>
#include <iomanip>

int main()
{
    std::string user_choice = "";
    Phonebook ph_book;
    int contact_number = 0;
    
    std::cout << "Welcome to the Phonebook" << std::endl;
    while (user_choice != "EXIT")
    {
        std::cout << "Please, choose one of the functionnality between ADD, SEARCH AND EXIT" << std::endl;
        std::cin >> user_choice;
        if (!std::cin)
        {
            std::cout << "Error with the cin, program exiting" << std::endl;
            return (1);
        }
        if (user_choice == "ADD")
        {
            contact_number = ph_book.get_nb_contact();
            if (contact_number == 8)
                contact_number = 0;
            ph_book.add_contact(contact_number);
        }
        else if (user_choice == "SEARCH")
        {
            ph_book.search_contact();
        }
    }
}
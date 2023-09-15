/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:16:07 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/15 13:53:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>

//? Quand je ADD, 5 contact sont detruit donc celui que je viens de construire 
//! FIX : Quand j'ai passer le tableau contacts de phonebook en public ca n'a plus destroy tout les contacts ect

//? 2ieme cout s'affiche 3 fois apres avoir ajouter un contact
//! Ca a l'air fix

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
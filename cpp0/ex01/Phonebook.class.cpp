/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:41:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/18 13:20:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook( void )
{
    return ;
}

Phonebook::~Phonebook( void )
{
    return ;
}

int Phonebook::get_nb_contact( void ) const 
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (this->contacts[i].get_first_name().empty())
            return (i);
    }
    return (i);
}

void trunc_or_not( std::string string)
{
	if (string.size() > 10)
		std::cout << std::setw(9) << string.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << string;
}

void Phonebook::add_contact(int index)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string dark_secret;

    std::cout << "Let's get the information about the new contact" << std::endl;
    std::cout << "Enter the first name" << std::endl;
    std::cin >> first_name;
    std::cout << "Enter the last name" << std::endl;
    std::cin >> last_name;
    std::cout << "Enter the nickname" << std::endl;
    std::cin >> nickname;
    std::cout << "Enter the phone number" << std::endl;
    std::cin >> phone_number;
    std::cout << "Enter the darkest secret" << std::endl;
    std::cin >> dark_secret;

    this->contacts[index].set_first_name(first_name);
    this->contacts[index].set_last_name(last_name);
    this->contacts[index].set_nickname(nickname);
    this->contacts[index].set_phone_number(phone_number);
    this->contacts[index].set_dark_secret(dark_secret);
}

void Phonebook::search_contact( void ) const
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (this->contacts[i].get_first_name().empty() == false)
        {
            std::cout << i + 1 << "| ";
			trunc_or_not(this->contacts[i].get_first_name());
			std::cout << "| ";
            trunc_or_not(this->contacts[i].get_last_name());
			std::cout << "| ";
            trunc_or_not(this->contacts[i].get_nickname());
			std::cout << "| " << std::endl;
        }
    }
    std::cout << "Enter the number of the contact you want" << std::endl;
    std::cin >> i;
    while (i > 8)
    {
        if (i > this->get_nb_contact())
            std::cout << "Choose a number in the list" << std::endl;
        else
            std::cout << "Choose between 1 and 8 please" << std::endl;
        std::cin >> i;
    }
    std::cout << this->contacts[i - 1].get_first_name() << std::endl;
    std::cout << this->contacts[i - 1].get_last_name() << std::endl;
    std::cout << this->contacts[i - 1].get_nickname() << std::endl;
    std::cout << this->contacts[i - 1].get_phone_number() << std::endl;
    std::cout << this->contacts[i - 1].get_dark_secret() << std::endl;
}
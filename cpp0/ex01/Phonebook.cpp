/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:41:25 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/19 23:30:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook( void )
{
    return ;
}

Phonebook::~Phonebook( void )
{
    return ;
}

void    exit_error()
{
    std::cout << "Error: cin closed, program exiting" << std::endl;
	Phonebook::printLine();
	Phonebook::printHeader("GOODBYE :(");
    exit(1);
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
	Phonebook::printLine();
    std::cout << "CONTACT FIRST NAME: ";
    std::cin >> first_name;
    if (!std::cin)
	{
		exit_error();
	}
	std::cout << "\n";
	Phonebook::printLine();
    std::cout << "CONTACT LAST NAME: ";
    std::cin >> last_name;
    if (!std::cin)
	{
        exit_error();
	}
	std::cout << "\n";
	Phonebook::printLine();
    std::cout << "CONTACT NICKNAME: ";
    std::cin >> nickname;
    if (!std::cin)
	{
        exit_error();
	}
	std::cout << "\n";
	Phonebook::printLine();
    std::cout << "CONTACT PHONE-NUMBER: ";
    std::cin >> phone_number;
    if (!std::cin)
	{
        exit_error();
	}
	std::cout << "\n";
	Phonebook::printLine();
    std::cout << "CONTACT DARK-SECRET: ";
    std::cin >> dark_secret;
    if (!std::cin)
	{
        exit_error();
	}
    this->contacts[index].set_first_name(first_name);
    this->contacts[index].set_last_name(last_name);
    this->contacts[index].set_nickname(nickname);
    this->contacts[index].set_phone_number(phone_number);
    this->contacts[index].set_dark_secret(dark_secret);
}

void Phonebook::printLine( void )
{
    for (int i = 0; i < 80; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

void Phonebook::printHeader( std::string head )
{
	int length;

	length = head.size() + 11;
    for (int i = 0; i < length; i++)
	{
        std::cout << "=";
	}
    std::cout << "\n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "|";
		for (int y = 0; y < length - 2; y++)
		{
			std::cout << " ";
		}
		std::cout << "|\n";
	}
	std::cout << "|";
    for (int i = 0; i < 5; i++)
	{
        std::cout << " ";
	}
    std::cout << head;
    for (int i = 0; i < 4; i++)
	{
    	std::cout << " ";
	}
	std::cout << "|\n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "|";
		for (int y = 0; y < length - 2; y++)
		{
			std::cout << " ";
		}
		std::cout << "|\n";
	}
	 for (int i = 0; i < length; i++)
	{
        std::cout << "=";
	}
	std::cout << "\n";
}

void Phonebook::search_contact( void ) const
{
    int i;
    std::string input;
    
    Phonebook::printLine();
    if (get_nb_contact() == 0)
    {
        std::cout << "There is no contact\n";
		std::cout << "Let's add some !\n";
        return ;
    }
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
    printLine();
    std::cout << "Enter the number of a contact for more info " << std::endl;
    while (1)
    {
        printLine();
        std::cout << "Contact : ";
        std::cin >> input;
        if (!std::cin)
            exit_error();
        printLine();
        if (input.length() > 1 || isdigit(input[0]) == 0)
        {
            std::cout << "Type a NUMBER with only ONE digit!" << std::endl;
            continue;
        }
        i = (int)input[0] - 48;
        if (i > 8 || i <= 0 || i > this->get_nb_contact())
        {
            std::cout << "Check the list before to choose wisely !" << std::endl;
            continue;
        }
        else
            break;
    }
    std::cout << "FIRST NAME: " << this->contacts[i - 1].get_first_name() << std::endl;
    std::cout << "LAST NAME: " << this->contacts[i - 1].get_last_name() << std::endl;
    std::cout << "NICKNAME: " << this->contacts[i - 1].get_nickname() << std::endl;
    std::cout << "PHONE-NUMBER: " << this->contacts[i - 1].get_phone_number() << std::endl;
    std::cout << "DARK-SECRET: " << this->contacts[i - 1].get_dark_secret() << std::endl;
}
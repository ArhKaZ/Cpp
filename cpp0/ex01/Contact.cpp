/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:40:13 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/15 13:56:03 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <iostream>

Contact::Contact(void)
{
    return ;
}

Contact::~Contact( void )
{
    return ;
}

std::string Contact::get_last_name( void ) const
{
    return this->last_name;
}

std::string Contact::get_first_name( void ) const
{
    return this->first_name;
}

std::string Contact::get_nickname( void ) const
{
    return this->nickname;
}

std::string Contact::get_phone_number( void ) const
{
    return this->phone_number;
}

std::string Contact::get_dark_secret( void ) const
{
    return this->darkest_secret;
}

void Contact::set_last_name( std::string ln )
{
    this->last_name.assign(ln);
}
void Contact::set_first_name( std::string fn )
{
    this->first_name.assign(fn);
}
void Contact::set_nickname( std::string nm)
{
    this->nickname.assign(nm);
}
void Contact::set_phone_number( std::string nb)
{
    this->phone_number.assign(nb);
}
void Contact::set_dark_secret( std::string ds)
{
    this->darkest_secret.assign(ds);
}
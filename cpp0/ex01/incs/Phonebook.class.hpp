/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:42:16 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/19 23:04:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "Contact.class.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
class Phonebook
{
    public:

    Phonebook( void );
    ~Phonebook( void );
    int get_nb_contact( void ) const;
    void search_contact( void ) const;
    void add_contact( int );
    Contact contacts[8];
    static void printLine( void );
    static void printHeader( std::string head );
};

#endif
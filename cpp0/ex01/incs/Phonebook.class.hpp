/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:42:16 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/15 13:54:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "Contact.class.hpp"

class Phonebook
{
    public:

    Phonebook( void );
    ~Phonebook( void );
    int get_nb_contact( void ) const;
    void search_contact( void ) const;
    void add_contact( int );
    Contact contacts[8];
};

#endif
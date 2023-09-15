/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:40:43 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/15 13:54:23 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <iostream>

class Contact 
{
    public:

    Contact( void );
    ~Contact( void );
    std::string get_last_name( void ) const ;
    std::string get_first_name( void ) const;
    std::string get_nickname( void ) const;
    std::string get_phone_number( void ) const;
    std::string get_dark_secret( void ) const;
    void set_last_name( std::string );
    void set_first_name( std::string );
    void set_nickname( std::string );
    void set_phone_number( std::string );
    void set_dark_secret( std::string );
    
    private:
    
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

#endif
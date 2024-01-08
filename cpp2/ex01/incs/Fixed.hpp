/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:08:17 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/04 11:52:45 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
    private:
        int _value;
        const static int _nb_fra = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed(const int i);
        Fixed(const float i);
        Fixed &operator=(const Fixed &f);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt ( void ) const;
};

std::ostream &operator<<(std::ostream &op, Fixed const &f);

#endif

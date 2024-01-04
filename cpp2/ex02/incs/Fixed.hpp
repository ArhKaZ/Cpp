/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:08:17 by syluiset          #+#    #+#             */
/*   Updated: 2023/12/06 20:29:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        Fixed operator+(const Fixed &f);
        Fixed operator-(const Fixed &f);
        Fixed operator*(const Fixed &f);
        Fixed operator/(const Fixed &f);
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt ( void ) const;
        static Fixed &min(Fixed &f1, Fixed &f2);
        static Fixed min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static Fixed max(const Fixed &f1, const Fixed &f2); 
};

std::ostream &operator<<(std::ostream &op, Fixed const &f);
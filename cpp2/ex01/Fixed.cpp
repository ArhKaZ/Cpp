/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:07:21 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/22 10:09:04 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "incs/Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}
Fixed::Fixed(const int nb) : _value( nb << _nb_fra)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb) : _value( roundf(nb * (1 << _nb_fra)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = f.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destuctor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat( void ) const {
   return (static_cast< float >(this->_value) / (1 << _nb_fra)); 
}

int Fixed::toInt( void ) const {
    return (this->_value >> _nb_fra);
}

std::ostream &operator<<(std::ostream &op, Fixed const &f)
{
    op << f.toFloat();
    return (op);
}
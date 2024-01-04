/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:07:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/12/06 20:29:56 by syluiset         ###   ########.fr       */
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
    this->_value = f.getRawBits();
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
    std::cout << "getRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed &other) const
{
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const 
{
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const 
{
    return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed &other)
{
   return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other)
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)
{
    return Fixed(this->toFloat()/ other.toFloat());
}

Fixed &Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return (temp);
}

Fixed &Fixed::operator--()
{
    --_value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return (temp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1._value < f2._value)
        return (f1);
    else
        return (f2);
}

Fixed Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1._value < f2._value)
        return (f1);
    else
        return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1._value > f2._value)
        return (f1);
    else
        return (f2);    
}

Fixed Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1._value > f2._value)
        return (f1);
    else
        return (f2);    
}
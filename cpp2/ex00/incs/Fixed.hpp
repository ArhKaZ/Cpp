/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:08:17 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/04 11:52:36 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int value;
        const static int nb_fra = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed &operator=(const Fixed &f);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif

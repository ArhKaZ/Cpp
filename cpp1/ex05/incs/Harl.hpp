/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:24:51 by syluiset          #+#    #+#             */
/*   Updated: 2023/11/27 15:55:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Harl {
    private: 
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
    public: 
    Harl();
    ~Harl();
    void complain(std::string level);

};
    typedef void (Harl::*t_alert)( void );
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:03:09 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 16:36:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <stdlib.h>
#include <time.h>

class TypeBase
{
public:
	virtual ~TypeBase();
	TypeBase* generate(void);
	void identify(TypeBase* p);
	void identify(TypeBase& p);
};

#endif

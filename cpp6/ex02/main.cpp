/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:38:14 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:48 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Base.hpp"

int main()
{
	TypeBase *b1 = TypeBase::generate();
	TypeBase *b2 = TypeBase::generate();
	TypeBase *b3 = TypeBase::generate();
	TypeBase *b4 = TypeBase::generate();

	TypeBase::identify(b1);
	TypeBase::identify(b2);
	TypeBase::identify(*b3);
	TypeBase::identify(*b4);
}
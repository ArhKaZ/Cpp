/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:20:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:14 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Base.hpp"
#include "incs/A.hpp"
#include "incs/B.hpp"
#include "incs/C.hpp"
TypeBase::~TypeBase() {}

void TypeBase::identify(TypeBase &p)
{
		A &refA = dynamic_cast<A &>(p);
		std::cout << "Ref is a A type !" << &refA;
		B& refB = dynamic_cast<B &>(p);
		std::cout << "Ref is a B type !" << &refB;
		C& refC = dynamic_cast<C &>(p);
		std::cout << "Ref is a C type !" << &refC;
}

void TypeBase::identify(TypeBase *p)
{
	A *ptrA;
	B *ptrB;
	C *ptrC;

	ptrA = dynamic_cast<A *>(p);
	ptrB = dynamic_cast<B *>(p);
	ptrC = dynamic_cast<C *>(p);
	if (ptrA != NULL)
	{
		std::cout << "Pointeur is a A type !";
		return;
	}
	if (ptrB != NULL)
	{
		std::cout << "Pointeur is a B type !";
		return;
	}
	if (ptrC != NULL)
	{
		std::cout << "Pointeur is a C type !";
		return;
	}
}


TypeBase *TypeBase::generate()
{
	int rando;
	TypeBase *p;
	srand(time(NULL));
	rando = rand() % 3 + 1;
	if (rando == 1)
		p = new A();
	if (rando == 2)
		p = new B();
	if (rando == 3)
		p = new C();
	return (p);
}
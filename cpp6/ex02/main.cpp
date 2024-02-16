/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:38:14 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/16 11:36:31 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Base.hpp"
#include "incs/A.hpp"
#include "incs/B.hpp"
#include "incs/C.hpp"

void identify(TypeBase &p)
{
	try
	{
		A& refA = dynamic_cast<A &>(p);
		std::cout << "Ref is a A type !" << std::endl;
		(void)refA;
	}
	catch (std::exception &e){}
	try
	{
		B &refB = dynamic_cast<B &>(p);
		std::cout << "Ref is a B type !" << std::endl ;
		(void)refB;
	}
	catch (std::exception &e){}
	try
	{
		C &refC = dynamic_cast<C &>(p);
		std::cout << "Ref is a C type !" << std::endl;
		(void)refC;
	}
	catch (std::exception &e){}
}

void identify(TypeBase *p)
{
	A *ptrA;
	B *ptrB;
	C *ptrC;

	ptrA = dynamic_cast<A *>(p);
	ptrB = dynamic_cast<B *>(p);
	ptrC = dynamic_cast<C *>(p);
	if (ptrA != NULL)
	{
		std::cout << "Pointeur is a A type !" << std::endl;
		return;
	}
	if (ptrB != NULL)
	{
		std::cout << "Pointeur is a B type !" << std::endl;
		return;
	}
	if (ptrC != NULL)
	{
		std::cout << "Pointeur is a C type !" << std::endl;
		return;
	}
}


TypeBase* generate()
{
	int rando = 0;
	TypeBase *p;

	rando = rand() % 3 + 1;
	if (rando == 1)
		p = new A();
	if (rando == 2)
		p = new B();
	if (rando == 3)
		p = new C();
	return (p);
}

int main()
{
	srand(time(NULL));
	TypeBase *b1 = generate();
	TypeBase *b2 = generate();
	TypeBase *b3 = generate();
	TypeBase *b4 = generate();

	std::cout << "Pointeur b1 : ";
	identify(b1);
	std::cout << "Ref b1 : ";
	identify(*b1);
	std::cout << "Pointeur b2 : ";
	identify(b2);
	std::cout << "Ref b2 : ";
	identify(*b2);
	std::cout << "Pointeur b3 : ";
	identify(b3);
	std::cout << "Ref b3 : ";
	identify(*b3);
	std::cout << "Pointeur b4 : ";
	identify(b4);
	std::cout << "Ref b4 : ";
	identify(*b4);

	delete b1;
	delete b2;
	delete b3;
	delete b4;
}
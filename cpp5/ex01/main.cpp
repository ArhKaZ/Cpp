/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:14:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat *b = new Bureaucrat("Sylvain", 10);
	Bureaucrat *c = new Bureaucrat("Antoine", 2);
	Bureaucrat *d = new Bureaucrat("Xavier", 149);
    Form *f1 = new Form("C1234", 5, 16);
    Form *f2 = new Form("C124", 39, 140);
	d->downGrade();
	d->downGrade();
	c->incrGrade();
	c->incrGrade();
	std::cout << *c;
	std::cout << *b;
	std::cout << *d;
    std::cout << *f1;
    std::cout << *f2;
    std::cout << "f1 sign : " << f1->getSign() << std::endl;
    f1->beSigned(*d);
    f1->beSigned(*c);
    std::cout << "f1 sign : " << f1->getSign() << std::endl;
    d->signForm(*f2);
    b->signForm(*f2);
	delete b;
	delete c;
	delete d;
    delete f1;
    delete f2;
}

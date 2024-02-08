/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:21 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"

int main()
{
	Bureaucrat *b = new Bureaucrat("Sylvain", 10);
	Bureaucrat *c = new Bureaucrat("Antoine", 2);
	Bureaucrat *d = new Bureaucrat("Xavier", 149);
    Bureaucrat *w = new Bureaucrat("Bidon", 3240);
    Bureaucrat *q = new Bureaucrat("Bidon2", 0);

	d->downGrade();
	d->downGrade();
	c->incrGrade();
	c->incrGrade();
	std::cout << *c;
	std::cout << *b;
	std::cout << *d;
	delete b;
	delete c;
	delete d;
    delete w;
    delete q;
}

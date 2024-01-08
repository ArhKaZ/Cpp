/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:37 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 14:36:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Bureaucrat.hpp"

int main()
{
	Bureaucrat *b = new Bureaucrat("Sylvain", 10);
	Bureaucrat *c = new Bureaucrat("Antoine", 2);
	Bureaucrat *d = new Bureaucrat("Xavier", 149);

	d->downGrade();
	d->downGrade();
	c->incrGrade();
	c->incrGrade();
	std::cout << c << std::endl;
	std::cout << b << std::endl;
	std::cout << d << std::endl;
	delete b;
	delete c;
	delete d;
}

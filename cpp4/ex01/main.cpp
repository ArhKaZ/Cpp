/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:42:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 21:51:31 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Animal.hpp"
#include "incs/Cat.hpp"
#include "incs/Dog.hpp"
#include "incs/WrongAnimal.hpp"
#include "incs/WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Dog* t = new Dog();
	Cat* c = new Cat();
	c->add_idea("Manger paté", 0);
	c->add_idea("Manger croquette", 8);
	const Cat* cp = c;
	c->print_ideas();
	cp->print_ideas();
	delete j;
	delete i;
	delete t;
	delete cp;
	return 0;
	return 0;
}

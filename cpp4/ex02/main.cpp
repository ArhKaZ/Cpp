/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:42:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/08 10:39:05 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Animal.hpp"
#include "incs/Cat.hpp"
#include "incs/Dog.hpp"
#include "incs/WrongAnimal.hpp"
#include "incs/WrongCat.hpp"

int main()
{
	const Animal* j = new Animal();
	const Animal* i = new Animal();
	const Dog* t = new Dog();
	const Cat* c = new Cat();
	const Cat* cp = c;
	delete j;
	delete i;
	delete t;
	delete cp;
	return 0;
	return 0;
}

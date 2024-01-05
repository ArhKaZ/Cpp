/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:42:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/05 15:49:45 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Animal.hpp"
#include "incs/Cat.hpp"
#include "incs/Dog.hpp"
#include "incs/WrongAnimal.hpp"
#include "incs/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongCat *wrongi = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << wrongi->getType() << " " << std::endl;
	wrongmeta->makeSound();
	wrongi->makeSound();
	return 0;
}
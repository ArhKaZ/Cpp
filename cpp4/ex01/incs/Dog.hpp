/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:31:10 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 21:53:16 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain* _brain;

	public:
	Dog();
	~Dog();
	void print_ideas() const;
	void add_idea(std::string idea, int index);
	Dog &operator=(const Dog &c);
};

#endif

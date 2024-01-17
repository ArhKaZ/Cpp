/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:31:08 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 21:54:40 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
	Brain* _brain;
	public :
	Cat();
	~Cat();
	void print_ideas() const;
	void add_idea(std::string idea, int index);
	Cat &operator=(const Cat &c);
};

#endif

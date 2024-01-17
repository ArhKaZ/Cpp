/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:04 by syluiset          #+#    #+#             */
/*   Updated: 2024/01/17 21:50:45 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
	private:
	std::string ideas[100];
	public :
	Brain();
	~Brain();
	void set_ideas(std::string idea, int index);
	std::string get_ideas(int index);
	void copy_ideas(Brain &brain);
};

#endif

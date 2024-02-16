/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:19:10 by syluiset          #+#    #+#             */
/*   Updated: 2024/02/16 15:47:23 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/whatever.hpp"

int main()
{
	int nb1 = 49;
	int nb2 = 84;
	float nbf1 = 124.04f;
	float nbf2 = 124.25f;
	std::string s1 = "Je suis du c++";
	std::string s2 = "Je suis pas du c++";

	std::cout << "Swap test : " << std::endl;
	std::cout << "Nb1 : " << nb1 << " / Nb2 : " << nb2 << std::endl;
	::swap<int>(nb1, nb2);
	std::cout << "Nb1 : " << nb1 << " / Nb2 : " << nb2 << std::endl;

	std::cout << "Float1 : " << nbf1 << " / Float2 : " << nbf2 << std::endl;
	::swap<float>(nbf1, nbf2);
	std::cout << "Float1 : " << nbf1 << " / Float2 : " << nbf2 << std::endl;

	std::cout << "String1 : " << s1 << " / String2 : " << s2 << std::endl;
	::swap<std::string>(s1, s2);
	std::cout << "String1 : " << s1 << " / String2 : " << s2 << std::endl;

	std::cout << "Min/Max test : " << std::endl;
	std::cout << "Min between " << nb1 << " and " << nb2 << " : " << ::min<int>(nb1, nb2) << std::endl;
	std::cout << "Min between " << nbf1 << " and " << nbf2 << " : " << ::min<float>(nbf1, nbf2) << std::endl;
	std::cout << "Min between " << s1 << " and " << s2 << " : " << ::min<std::string>(s1, s2) << std::endl;
	std::cout << "Max between " << nb1 << " and " << nb2 << " : " << ::max<int>(nb1, nb2) << std::endl;
	std::cout << "Max between " << nbf1 << " and " << nbf2 << " : " << ::max<float>(nbf1, nbf2) << std::endl;
	std::cout << "Max between " << s1 << " and " << s2 << " : " << ::max<std::string>(s1, s2) << std::endl;
}

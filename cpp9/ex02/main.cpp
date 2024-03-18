/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:21:45 by syluiset          #+#    #+#             */
/*   Updated: 2024/03/18 22:27:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/PmergeMe.hpp"

bool containsDuplicates(const std::list<int>& lst) {
    std::list<int>::const_iterator it, it2;
    for (it = lst.begin(); it != lst.end(); ++it) {
        it2 = it;
        for (++it2; it2 != lst.end(); ++it2) {
            if (*it == *it2) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{
	size_t size_inputs;
	PmergeMe *PM;
	if (argc > 2)
	{
		try
		{
			PM = new PmergeMe(argv);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			return (-1);
		}
		if (containsDuplicates(PM->getLst()))
		{
			std::cout << "Number are duplicate";
			delete PM;
			return -1;
		}
		size_inputs = PM->getLst().size();
		std::cout << "Before: ";
		PM->displayList();
		PM->vecSort();
		PM->lstSort();
		std::cout << "After: ";
		PM->displayVector();
		PM->displayList();
		std::cout << "Time to process a range of " << size_inputs << " elements with std::list : " << std::fixed << std::setprecision(5) << PM->getTimeList() << " us\n";
		std::cout << "Time to process a range of " << size_inputs << " elements with std::vector : " << std::fixed << std::setprecision(5) << PM->getTimeVec() << " us\n";
		delete PM;
	}
}
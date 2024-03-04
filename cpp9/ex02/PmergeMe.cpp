/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:49:55 by syluiset          #+#    #+#             */
/*   Updated: 2024/03/04 20:56:42 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() 
{
	this->vecPm.erase(this->vecPm.begin(), this->vecPm.end());
	this->lstPm.erase(this->lstPm.begin(), this->lstPm.end());
}

PmergeMe::PmergeMe(char **argv)
{
	long int tmp = 0;
	int j = 0;
	for (size_t i = 1; argv[i] != NULL; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
				throw NumericError();
			j++;
		}
		tmp = atoi(argv[i]);
		if (tmp > std::numeric_limits<int>::max() || tmp < 0)
		{
			this->lstPm.erase(this->lstPm.begin(), this->lstPm.end());
			throw NumericError();
		}
		this->lstPm.push_back(tmp);
		this->vecPm.push_back(tmp);
	}
}

PmergeMe::PmergeMe(const PmergeMe &Pm) : vecPm(Pm.vecPm), lstPm(Pm.lstPm) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &Pm)
{
	this->lstPm = Pm.lstPm;
	this->vecPm = Pm.vecPm;
	return *this;
}

const char *PmergeMe::NumericError::what() const throw()
{
	return "Error with inputs";
}
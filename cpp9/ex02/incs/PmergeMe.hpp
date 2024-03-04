/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:12:58 by syluiset          #+#    #+#             */
/*   Updated: 2024/03/04 20:59:55 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP9_PMERGEME_HPP
#define CPP9_PMERGEME_HPP
#include <vector>
#include <string>
#include <limits>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <list>
#include <iomanip>

class PmergeMe
{
public:
	class NumericError : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &Pm);
	PmergeMe(char **argv);
	PmergeMe &operator=(const PmergeMe &Pm);

	void vecSort();
	void displayVector() const;

	void lstSort();
	std::list<int> getLst() const;
	void displayList() const;

	double getTimeList() const;
	double getTimeVec() const;
	
private:
	std::vector<int> vecPm;
	std::list<int> lstPm;
	double timeList;
	double timeVec;
};

#endif // CPP9_PMERGEME_HPP

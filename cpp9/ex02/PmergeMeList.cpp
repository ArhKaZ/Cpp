/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:38:52 by syluiset          #+#    #+#             */
/*   Updated: 2024/03/04 20:48:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/PmergeMe.hpp"

void print_lst(std::list<int> v1, std::list<int> v2)
{
	std::list<int>::iterator itV1;
	std::list<int>::iterator iteV1 = v1.end();
	std::list<int>::iterator itV2;
	std::list<int>::iterator iteV2 = v2.end();

	for(itV1 = v1.begin(); itV1 != iteV1; itV1++)
	{
		std::cout << "V1: " << *itV1 << "/ ";
	}
	std::cout << "\n";
	for(itV2 = v2.begin(); itV2 != iteV2; itV2++)
	{
		std::cout << "V2: " << *itV2 << "/ ";
	}
	std::cout << "\n";
}

std::list<int> merging(std::list<int> lstBig, std::list<int> lstLittle, int jac)
{
	std::list<int>::iterator itLittle = lstLittle.begin();
	std::list<int>::iterator itBig = lstBig.begin();
	std::list<int>::iterator itnextBig;
	int midBig = lstBig.size() / 2;
	int i = 1;
	while (i < jac)
	{
		itLittle++;
		i++;
	}
	i = 1;
	while (i < midBig)
	{
		itBig++;
		i++;
	}
	itnextBig = itBig;
	itnextBig++;
	while (!(*itLittle > *itBig && *itLittle < *itnextBig))
	{
		if (*itLittle < *itBig)
		{
			
		}
	}
}

std::list<int> PmergeMe::fusion(PmergeMe::pairsList lst, bool isOdd, int odd)
{
	std::list<int> lstBig;
	std::list<int> lstLittle;
	std::list<int> res;
	pairsList::iterator it;

	for(it = lst.begin(); it != lst.end(); it++)
	{
		lstBig.push_back(it->first);
		lstLittle.push_back(it->second);
	}
	res =
}

PmergeMe::pairsList PmergeMe::divideInPairs(std::list<int> myLst)
{
	pairsList pairLst;
	std::list<int>::iterator itnow = myLst.begin();
	std::list<int>::iterator itnext;
	std::pair<int,int> pairs;

	while (myLst.size() >= 2)
	{
		itnext = itnow;
		itnext++;
		if (*itnow < *itnext)
		{
			pairLst.push_back(std::pair<int, int>(*itnext, *itnow));
		}
		else
		{
			pairLst.push_back(std::pair<int, int>(*itnow, *itnext));
		}
		myLst.pop_front();
		itnow = itnext;
		itnow++;
		myLst.pop_front();
	}
	return (pairLst);
}

PmergeMe::pairsList PmergeMe::sortPairs(std::list<std::pair<int, int> > myLst)
{
	pairsList newList;
	pairsList::iterator it = myLst.begin();
	pairsList::iterator itnext;

	while (myLst.size() >= 2)
	{
		itnext = it;
		itnext++;
		if (it->first > itnext->first)
		{
			newList.push_back(*itnext);
			newList.push_back(*it);
		}
		else
		{
			newList.push_back(*it);
			newList.push_back(*itnext);
		}
		myLst.pop_front();
		it = itnext;
		it++;
		myLst.pop_front();
	}
	return (newList);
}

void displayLst(std::list<std::pair<int, int> > lst)
{
	std::list<std::pair<int, int> >::iterator it;
	std::list<std::pair<int, int> >::iterator ite = lst.end();
	for (it = lst.begin(); it != ite; it++)
	{
		std::cout << "first : " << it->first << " seconde : " << it->second << std::endl;
	}
}

void PmergeMe::lstSort()
{
	clock_t timeBegin, timeEnd;
	bool isOdd = false;
	int odd = 0;
	pairsList tmp;

	if (this->lstPm.size() % 2 == 1)
	{
		is_odd = true;
		odd = *lstPm.end();
		lstPm.pop_back();
	}
	timeBegin = clock();
	tmp = divideInPairs(this->lstPm);
	displayLst(tmp);
	tmp = sortPairs(tmp);
	std::cout << "next : " << std::endl;
	displayLst(tmp);
	timeEnd = clock();
	this->timeList = static_cast<double>(timeEnd - timeBegin) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayList() const
{
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = this->lstPm.end();

	for(it = this->lstPm.begin(); it != ite; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

double PmergeMe::getTimeList() const
{
	return this->timeList;
}

std::list<int> PmergeMe::getLst() const
{
	return this->lstPm;
}
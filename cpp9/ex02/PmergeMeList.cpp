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

std::list<int> fusion(std::list<int> v1, std::list<int> v2)
{
	std::list<int> res;
	std::list<int>::iterator itV1 = v1.begin();
	std::list<int>::iterator iteV1 = v1.end();
	std::list<int>::iterator itV2 = v2.begin();
	std::list<int>::iterator iteV2 = v2.end();
	
	while (itV1 != iteV1 && itV2 != iteV2)
	{
		if (*itV1 < *itV2)
		{
			res.push_back(*itV1);
			itV1++;
		}
		else
		{
			res.push_back(*itV2);
			itV2++;
		}
	}
	if (itV1 != iteV1)
	{
		res.insert(res.end(), itV1, iteV1);
	}
	else if (itV2 != iteV2)
	{
		res.insert(res.end(), itV2, iteV2);
	}
	return (res);
}

std::list<int> divideAndMergeLst(std::list<int> Mylst)
{
	std::list<int> lstHigh;
	std::list<int> lstLow;
	std::list<int>::iterator itnow = Mylst.begin();
	std::list<int>::iterator itnext = Mylst.begin();
	std::list<int>::iterator ite = Mylst.end();
	
	if (Mylst.size() <= 1)
		return Mylst;
	itnext++;
	while (itnow != ite)
	{
		if (itnext != ite)
		{
			if (*itnow < *itnext)
			{
				lstHigh.push_back(*itnext);
				lstLow.push_back(*itnow);
			}	
			else
			{
				lstHigh.push_back(*itnow);
				lstLow.push_back(*itnext);
			}
			itnow = itnext;
			itnow++;
		}
		else
		{
			lstLow.push_back(*itnow);
			break;
		}
		if (itnow != ite)
		{
			itnext = itnow;
			itnext++;
		}
	}
	lstHigh = divideAndMergeLst(lstHigh);
	lstLow = divideAndMergeLst(lstLow);
	return (fusion(lstHigh, lstLow));
}

void PmergeMe::lstSort()
{
	clock_t timeBegin, timeEnd;
	std::list<int> tmp;
	
	timeBegin = clock();
	tmp = divideAndMergeLst(this->lstPm);
	timeEnd = clock();
	this->timeList = static_cast<double>(timeEnd - timeBegin) / CLOCKS_PER_SEC * 1000000;
	this->lstPm = tmp;
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
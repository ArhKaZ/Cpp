/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:13:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/03/04 20:50:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> fusion(std::vector<int> v1, std::vector<int> v2)
{
	std::vector<int> res;
	std::vector<int>::iterator itV1 = v1.begin();
	std::vector<int>::iterator iteV1 = v1.end();
	std::vector<int>::iterator itV2 = v2.begin();
	std::vector<int>::iterator iteV2 = v2.end();
	
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

std::vector<int> divideAndMergeVec(std::vector<int> myVec)
{
	std::vector<int> vecHigh;
	std::vector<int> vecLow;
	std::vector<int>::iterator itnow = myVec.begin();
	std::vector<int>::iterator itnext = myVec.begin();
	std::vector<int>::iterator ite = myVec.end();
	
	if (myVec.size() <= 1)
		return myVec;
	itnext++;
	while (itnow != ite)
	{
		if (itnext != ite)
		{
			if (*itnow < *itnext)
			{
				vecHigh.push_back(*itnext);
				vecLow.push_back(*itnow);
			}	
			else
			{
				vecHigh.push_back(*itnow);
				vecLow.push_back(*itnext);
			}
			itnow = itnext;
			itnow++;
		}
		else
		{
			vecLow.push_back(*itnow);
			break;
		}
		if (itnow != ite)
		{
			itnext = itnow;
			itnext++;
		}
	}
	vecHigh = divideAndMergeVec(vecHigh);
	vecLow = divideAndMergeVec(vecLow);
	return (fusion(vecHigh, vecLow));
}

void PmergeMe::vecSort()
{
	clock_t timeBegin, timeEnd;
	std::vector<int> tmp;
	timeBegin = clock();
	tmp = divideAndMergeVec(this->vecPm);
	timeEnd = clock();
	this->timeVec = static_cast<double>(timeEnd - timeBegin) / CLOCKS_PER_SEC * 1000000;
	this->vecPm.erase(vecPm.begin(), vecPm.end());
	this->vecPm = tmp;
}

void PmergeMe::displayVector() const
{
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = this->vecPm.end();

	for(it = this->vecPm.begin(); it != ite; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

double PmergeMe::getTimeVec() const
{
	return this->timeVec;
}


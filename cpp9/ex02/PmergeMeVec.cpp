/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:13:03 by syluiset          #+#    #+#             */
/*   Updated: 2024/03/18 16:45:39 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void displayVec(std::vector<int> vec)
{
	std::vector<int>::iterator it;
	std::cout << "DisplayVec :";
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void merging(std::vector<int> *vecBig, std::vector<int> vecLittle, int jac)
{
	static int lastjac;
	int jactmp = jac;
	std::vector<int>::iterator itLittle;
	std::vector<int>::iterator itBig;
	std::vector<int>::iterator itnextBig;
	int midBig;
	int i;
	if (jac == 1)
	{
		vecBig->insert(vecBig->begin(), *vecLittle.begin());
		return;
	}
	if (jac > static_cast<int>(vecLittle.size()))
		jactmp = --jac;
	while (1)
	{
		itLittle = vecLittle.begin();
		itBig = vecBig->begin();
		for (i = 1; i < jactmp; i++)
		{
			itLittle++;
			if (itLittle == --vecLittle.end())
				break;
		}
		midBig = vecBig->size() / 2;
		for (i = 1; i < midBig; i++)
		{
			itBig++;
		}
		if (itBig == vecBig->end())
			itBig--;
		itnextBig = itBig;
		itnextBig++;
		while (!(*itLittle > *itBig && *itLittle < *itnextBig))
		{
			if (*itLittle < *itBig && itBig == vecBig->begin())
				break;
			if (*itLittle > *itnextBig && itnextBig == vecBig->end())
				break;
			else if (*itLittle > *itnextBig)
			{
				itBig++;
				itnextBig++;
			}
			else if (*itLittle < *itBig)
			{
				itBig--;
				itnextBig--;
			}
		}
		// std::cout << "vecBig :";
		// displayVec(*vecBig);
		// std::cout << "vecLittle :";
		// displayVec(vecLittle);
		// std::cout << "itLit : " << *itLittle;
		// std::cout << " itBig : " << *itBig;
		// std::cout << " itNext : " << *itnextBig << std::endl;
		// std::cerr << "size : " << vecBig->size();
		if (*itLittle < *itBig && itBig == vecBig->begin())
			vecBig->insert(itBig, *itLittle);
		else
			vecBig->insert(itnextBig, *itLittle);
		--jactmp;
		// std::cout << "jac :" << jac << " jactmp :" << jactmp << " lastjac" << lastjac << std::endl;
		if (jactmp == lastjac || jactmp == 1)
			break;
	}
	lastjac = jac;
}

void insert_odd(std::vector<int> *vecBig, int odd)
{
	std::vector<int>::iterator itBig = vecBig->begin();
	std::vector<int>::iterator itnextBig;
	itnextBig = itBig;
	itnextBig++;
	while (!(odd > *itBig && odd < *itnextBig))
	{
		if (odd < *itBig && itBig == vecBig->begin())
		{
			break;
		}
		else if (odd > *itnextBig)
		{
			itBig++;
			itnextBig++;
		}
		else if (odd < *itBig)
		{
			itBig++;
			itnextBig++;
		}
	}
	vecBig->insert(itnextBig, odd);
}

std::vector<int> PmergeMe::generateJacobstalVec(size_t size)
{
	std::cout << size;
	std::vector<int> jacob;
	jacob.reserve(20);
	jacob.push_back(1);
	jacob.push_back(3);
	std::vector<int>::iterator it = jacob.begin();
	std::vector<int>::iterator itnext = jacob.begin();
	itnext++;
	if (*itnext >= static_cast<int>(size))
		return (jacob);
	while (1)
	{
		if (*itnext + 2 * *it > static_cast<int>(size))
			break;
		jacob.push_back(*itnext + 2 * *it);
		it++;
		itnext++;
	}
	std::cerr << "cc";
	return (jacob);
}

bool contain(int nb, std::vector<int> con)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = con.end();

	for (it = con.begin(); it != ite; it++)
	{
		if (*it == nb)
			return true;
	}
	return false;
}

std::vector<int> PmergeMe::fusionVec(PmergeMe::pairsVec vec, bool isOdd, int odd)
{
	std::vector<int> vecBig;
	std::vector<int> vecLittle;
	std::vector<int> jacs;
	std::vector<int>::iterator itj;
	pairsVec::iterator it;
	std::vector<int>::iterator last;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		vecBig.push_back(it->first);
		vecLittle.push_back(it->second);
	}
	jacs = generateJacobstalVec(vecLittle.size());
	displayVec(jacs);
	for (itj = jacs.begin(); itj != jacs.end(); itj++)
	{
		merging(&vecBig, vecLittle, *itj);
		if (contain(*--vecLittle.end(), vecBig))
			break;
	}
	if (isOdd)
		insert_odd(&vecBig, odd);
	return (vecBig);
}

PmergeMe::pairsVec PmergeMe::divideInPairsVec(std::vector<int> myVec)
{
	pairsVec pairVec;
	std::vector<int>::iterator itnow = myVec.begin();
	std::vector<int>::iterator itnext;
	std::pair<int, int> pairs;

	while (1)
	{
		itnext = itnow;
		itnext++;
		if (*itnow < *itnext)
		{
			pairVec.push_back(std::pair<int, int>(*itnext, *itnow));
		}
		else
		{
			pairVec.push_back(std::pair<int, int>(*itnow, *itnext));
		}
		itnow = itnext;
		itnow++;
		if (itnow == myVec.end())
			break;
	}
	return (pairVec);
}

void PmergeMe::sortPairsVec(std::vector<std::pair<int, int> > *myVec)
{
	pairsVec newVec;
	pairsVec::iterator it = myVec->begin();
	pairsVec::iterator itnext;
	int tmp;

	while (1)
	{
		itnext = it;
		itnext++;
		if (it->first > itnext->first)
		{
			tmp = it->first;
			it->first = itnext->first;
			itnext->first = tmp;
			tmp = it->second;
			it->second = itnext->second;
			itnext->second = tmp;
			it = myVec->begin();
		}
		else
		{
			it = itnext;
		}
		if (it == --myVec->end())
			return;
	}
}

void PmergeMe::vecSort()
{
	clock_t timeBegin, timeEnd;
	bool isOdd = false;
	int odd = 0;
	pairsVec tmp;

	if (this->vecPm.size() % 2 == 1)
	{
		isOdd = true;
		odd = *--this->vecPm.end();
		vecPm.pop_back();
	}
	timeBegin = clock();
	tmp = divideInPairsVec(this->vecPm);
	sortPairsVec(&tmp);
	this->vecPm = fusionVec(tmp, isOdd, odd);
	timeEnd = clock();
	this->timeVec = static_cast<double>(timeEnd - timeBegin) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayVector() const
{
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = this->vecPm.end();
	size_t i = 0;
	
	for (it = this->vecPm.begin(); it != ite; it++)
	{
		if (i < 25 || this->vecPm.size() - i < 3)
			std::cout << *it << " ";
		else
		{
			if (i == 25)
				std::cout << "[...]";
		}
		i++;
	}
	std::cout << "\n";
}

double PmergeMe::getTimeVec() const
{
	return this->timeVec;
}

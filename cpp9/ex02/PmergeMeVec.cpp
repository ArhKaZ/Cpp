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
		lastjac = 0;
	while (1)
	{
		itLittle = vecLittle.begin();
		itBig = vecBig->begin();
		for (i = 1; i < jactmp; i++)
		{
			itLittle++;
			if (itLittle == --vecLittle.end())
			{
				break;
			}
		}
		midBig = vecBig->size() / 2;
		for (i = 1; i < midBig; i++)
		{
			itBig++;
		}
		itnextBig = itBig;
		itnextBig++;

		while (!(*itLittle > *itBig && *itLittle < *itnextBig))
		{
			if (*itLittle < *itBig && itBig == vecBig->begin())
			{
				break;
			}
			else if (*itLittle > *itnextBig)
			{
				i = midBig;
				midBig += vecBig->size() / 2 - (midBig - 1);
				std::cout << "midBig : " << midBig << "\n";
				while (i < midBig)
				{
					itBig++;
					itnextBig++;
					i++;
				}
				std::cout << "itBig after iter : " << *itBig << " itnext after iter : " << *itnextBig << "\n";
			}
			else if (*itLittle < *itBig)
			{
				i = midBig;
				midBig = midBig / 2;
				while (i > midBig)
				{
					itBig--;
					itnextBig--;
					i--;
				}
			}

		}
		if (*itLittle < *itBig && itBig == vecBig->begin())
			vecBig->insert(itBig, *itLittle);
		else
			vecBig->insert(itnextBig, *itLittle);
		if (jactmp - lastjac == 1)
			break;
		--jactmp;
	}
	lastjac = jac;
}

void insert_odd(std::vector<int> *vecBig, int odd)
{
	std::vector<int>::iterator itBig = vecBig->begin();
	std::vector<int>::iterator itnextBig;
	int midBig = vecBig->size() / 2;
	int i = 1;
	i = 1;
	while (i < midBig)
	{
		itBig++;
		i++;
	}
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
			i = midBig;
			midBig += 1;
			while (i < midBig)
			{
				itBig++;
				itnextBig++;
				i++;
			}
		}
		else if (odd < *itBig)
		{
			i = midBig;
			midBig -= 1;
			while (i > midBig)
			{
				itBig--;
				itnextBig--;
				i--;
			}
		}
	}
	vecBig->insert(itnextBig, odd);
}

std::vector<int> PmergeMe::generateJacobstalVec()
{
	std::vector<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	std::vector<int>::iterator it = jacob.begin();
	std::vector<int>::iterator itnext = jacob.begin()++;
	while (1)
	{
		jacob.push_back(*itnext + 2 * *it);
		it++;
		itnext++;
		if (*itnext >= static_cast<int>(this->vecPm.size()))
			break;
	}
	return (jacob);
}

bool contain(int nb, std::vector<int> con)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = con.end();

	for(it = con.begin(); it != ite; it++)
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

	for(it = vec.begin(); it != vec.end(); it++)
	{
		vecBig.push_back(it->first);
		vecLittle.push_back(it->second);
	}
	jacs = generateJacobstalVec();
	for (itj = jacs.begin(); itj != jacs.end(); itj++)
	{
		merging(&vecBig, vecLittle, *itj);
		std::cerr << "Liste apres merging ";
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
	std::pair<int,int> pairs;

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


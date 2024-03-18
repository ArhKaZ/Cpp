/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:38:52 by syluiset          #+#    #+#             */
/*   Updated: 2024/03/18 16:46:31 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/PmergeMe.hpp"

void displayLst(std::list<std::pair<int, int> > lst)
{
	std::list<std::pair<int, int> >::iterator it;
	std::list<std::pair<int, int> >::iterator ite = lst.end();
	for (it = lst.begin(); it != ite; it++)
	{
		std::cout << "first : " << it->first << " seconde : " << it->second << std::endl;
	}
}

void print_lst(std::list<int> v1)
{
	std::list<int>::iterator itV1;
	std::list<int>::iterator iteV1 = v1.end();

	for(itV1 = v1.begin(); itV1 != iteV1; itV1++)
	{
		std::cerr << *itV1 << " ";
	}
	std::cerr << "\n";
}

void merging(std::list<int> *lstBig, std::list<int> lstLittle, int jac)
{
	static int lastjac;
	int jactmp = jac;
	std::list<int>::iterator itLittle;
	std::list<int>::iterator itBig;
	std::list<int>::iterator itnextBig;
	int midBig;
	int i;
	if (jac == 1)
		lastjac = 0;
	if (jac > static_cast<int>(lstLittle.size()))
		jactmp = --jac;
	while (1)
	{
		std::cerr << "\nPremier while : \n";
		itLittle = lstLittle.begin();
		itBig = lstBig->begin();
		for (i = 1; i < jactmp; i++)
		{
			itLittle++;
			if (itLittle == --lstLittle.end())
				break;
		}
		midBig = lstBig->size() / 2;
		for (i = 1; i < midBig; i++)
		{
			itBig++;
		}
		itnextBig = itBig;
		itnextBig++;
		//std::cout << "itLit : " << *itLittle;
		//std::cout << " itBig : " << *itBig;
		//std::cout << " itNext : " << *itnextBig << std::endl; 
		//std::cerr << "size : " << lstBig->size();
		while (!(*itLittle > *itBig && *itLittle < *itnextBig))
		{
			//std::cout << "Seconde while \n";
			//std::cout << "itBig : " << *itBig << "itnext : " << *itnextBig << "\n"; 
			if (*itLittle < *itBig && itBig == lstBig->begin())
				break;
			if (*itLittle > *itnextBig && itnextBig == lstBig->end())
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
		//std::cout << "Sortie Deuxieme : \n";
		//std::cout << "lstBig :";
		//print_lst(*lstBig);
		//std::cout << "lstLittle :";
		//print_lst(lstLittle);
		//std::cout << "itLit : " << *itLittle;
		//std::cout << " itBig : " << *itBig;
		//std::cout << " itNext : " << *itnextBig << std::endl; 
		//std::cerr << "size : " << lstBig->size();
		if (*itLittle < *itBig && itBig == lstBig->begin())
			lstBig->insert(itBig, *itLittle);
		else
			lstBig->insert(itnextBig, *itLittle);
		--jactmp;
		//std::cout << "jac :" << jac << " jactmp :" << jactmp << " lastjac" << lastjac << "\n\n";
		if (jactmp == lastjac || jactmp == 1)
			break;
	}
	//std::cout << "Sortie premiere : \n";
	lastjac = jac;
}

void insert_odd(std::list<int> *lstBig, int odd)
{
	std::list<int>::iterator itBig = lstBig->begin();
	std::list<int>::iterator itnextBig;
	int midBig = lstBig->size() / 2;
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
		if (odd < *itBig && itBig == lstBig->begin())
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
	lstBig->insert(itnextBig, odd);
}

std::list<int> PmergeMe::generateJacobstalLst(size_t size)
{
	std::list<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	std::list<int>::iterator it = jacob.begin();
	std::list<int>::iterator itnext = jacob.begin();
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
	return (jacob);
}

bool contain(int nb, std::list<int> con)
{
	std::list<int>::iterator it;
	std::list<int>::iterator ite = con.end();

	for(it = con.begin(); it != ite; it++)
	{
		if (*it == nb)
			return true;
	}
	return false;
}

std::list<int> PmergeMe::fusionLst(PmergeMe::pairsList lst, bool isOdd, int odd)
{
	std::list<int> lstBig;
	std::list<int> lstLittle;
	std::list<int> 	jacs;
	std::list<int>::iterator itj;
	pairsList::iterator it;
	std::list<int>::iterator last;

	for(it = lst.begin(); it != lst.end(); it++)
	{
		lstBig.push_back(it->first);
		lstLittle.push_back(it->second);
	}
	jacs = generateJacobstalLst(lstLittle.size());
	for (itj = jacs.begin(); itj != jacs.end(); itj++)
	{
		merging(&lstBig, lstLittle, *itj);
		if (contain(*--lstLittle.end(), lstBig))
			break;
	}
	
	if (isOdd)
		insert_odd(&lstBig, odd);
	return (lstBig);
}

PmergeMe::pairsList PmergeMe::divideInPairsLst(std::list<int> myLst)
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

void PmergeMe::sortPairsLst(std::list<std::pair<int, int> > *myLst)
{
	pairsList newList;
	pairsList::iterator it = myLst->begin();
	pairsList::iterator itnext;
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
			it = myLst->begin();
		}
		else
		{
			it = itnext;
		}
		if (it == --myLst->end())
			return;
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
		isOdd = true;
		odd = *--this->lstPm.end();
		lstPm.pop_back();
	}
	timeBegin = clock();
	tmp = divideInPairsLst(this->lstPm);
	sortPairsLst(&tmp);
	this->lstPm = fusionLst(tmp, isOdd, odd);
	timeEnd = clock();
	this->timeList = static_cast<double>(timeEnd - timeBegin) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayList() const
{
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = this->lstPm.end();
	size_t i = 0;
	
	for(it = this->lstPm.begin(); it != ite; it++)
	{
		if (i < 25 || this->lstPm.size() - i < 3)
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

double PmergeMe::getTimeList() const
{
	return this->timeList;
}

std::list<int> PmergeMe::getLst() const
{
	return this->lstPm;
}

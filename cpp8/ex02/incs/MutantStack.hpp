#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
# include <stack>
# include <iostream>

template< typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack<T> &ms);
	MutantStack& operator=(const MutantStack<T> &ms);
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
	const_iterator cbegin()
	{
		return this->c.cbegin();
	}
	const_iterator cend()
	{
		return this->c.cend();
	}
	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}
	reverse_iterator rend()
	{
		return this->c.rend();
	}
	reverse_iterator crbegin()
	{
		return this->c.crbegin();
	}
	reverse_iterator crend()
	{
		return this->c.crrend();
	}
};

#endif
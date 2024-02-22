#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
# include <stack>
# include <iostream>

template< typename AttributeType, typename ContainerType >
class MutantStack : public std::stack<AttributeType>
{
public:
	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack<AttributeType> &ms);
	MutantStack& operator=(const MutantStack<AttributeType> &ms);
	typedef typename std::ContainerType::iterator it;
	typename ContainerType::iterator& begin()
	{
		return this->c.begin();
	}
};

#endif
#pragma once
#include <iostream>
#include <iterator>
#include <stack>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		iterator begin(void) {return (this->c.begin());}
		iterator end(void) {return (this->c.end());}

		typedef typename Container::const_iterator const_iterator;
		const_iterator begin(void) const {return (this->c.begin());}
		const_iterator end(void) const {return (this->c.end());}
};

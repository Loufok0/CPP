#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>


class E_NotFound : public std::exception
{
	private:
		const char* _msg;
	public:
		E_NotFound(void) : _msg("Target not found...") {}
		const char* what(void) const throw() {return (_msg);};
};


template <typename T>
typename std::vector<T>::iterator
easyfind(std::vector<T>& container, int target)
{
	typename std::vector<T>::iterator it;
	it = find(container.begin(), container.end(), target);
	if (it == container.end())
		throw(E_NotFound());
	return (it);
}

// this function has to find the first occurrence
// of the second parameter in the first parameter.

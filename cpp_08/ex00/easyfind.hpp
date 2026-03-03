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
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw E_NotFound();

	return it;
}
// this function has to find the first occurrence
// of the second parameter in the first parameter.

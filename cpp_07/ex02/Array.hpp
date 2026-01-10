#include <iostream>
#include <exception>
#include "./colors.hpp"

template <typename T>
class Array
{
	private:
		T *_arr;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator = (const Array &other);
		T& operator [] (size_t n);
		~Array();

		int size() const;

		class OutOfBound : public std::exception
		{
			private:
				const char* _msg;
			public:
				OutOfBound(void): _msg("Index out of bounds...") {};
				const char* what() const throw() {return _msg;}
		};

};

#include "./Array.tpp"

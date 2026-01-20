#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include <cmath>
#include <climits>
#include <algorithm>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>		S;
		unsigned int		_nElements;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator = (const Span& other);
		int operator [] (size_t n) const;
		~Span();


		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		void addMultipleNumber(int *n, unsigned int size);

		class OutOfBound : public std::exception
		{
			private:
				const char* _msg;
			public:
				OutOfBound(void): _msg("Index out of bounds...") {};
				const char* what() const throw() {return _msg;}
		};

		class TooMuchElements : public std::exception
		{
			private:
				const char* _msg;
			public:
				TooMuchElements(void): _msg("Too much elements in Span...") {};
				const char* what() const throw() {return _msg;}
		};

		class NotEnoughElements : public std::exception
		{
			private:
				const char* _msg;
			public:
				NotEnoughElements(void): _msg("Not enough elements in Span...") {};
				const char* what() const throw() {return _msg;}
		};
};


#include "./Span.hpp"

Span::Span(unsigned int n) : N(n), _nElements(0) {S.reserve(N);}

Span::Span(const Span& other)
{
	N = other.N;
	S = std::vector<int>(N);
	_nElements = other._nElements;

	unsigned int i = 0;
	while (++i < _nElements)
	{
		S[i] = other[i];
		i++;
	}
	
}

Span& Span::operator = (const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		S = std::vector<int>(N);
		_nElements = other._nElements;

		unsigned int i = 0;
		while (i < _nElements)
		{
			S[i] = other[i];
			i++;
		}
	}
	return (*this);
}

int Span::operator [] (size_t n) const
{
	if (n >= N || n >= _nElements)
		throw (OutOfBound());
	else
		return (S[n]);
}

Span::~Span() {}


void Span::addNumber(int n)
{
	if (_nElements < N)
	{
		S.push_back(n);
		_nElements++;
	}
	else
		throw(TooMuchElements());
}

int Span::shortestSpan()
{
	if (_nElements <= 1)
		throw(NotEnoughElements());

	std::vector<int> tmp(S);
	std::sort(tmp.begin(), tmp.end());

	unsigned int i = 0;
	int spna = INT_MAX;
	while (i < _nElements - 1)
	{
		if (labs(tmp[i + 1] - tmp[i]) < spna)
			spna = labs(tmp[i + 1] - tmp[i]);
		i++;
	}
	return (spna);
}

int Span::longestSpan()
{
	if (_nElements <= 1)
		throw(NotEnoughElements());

	int min = S[0];
	int max = S[0];
	unsigned int i = -1;
	while (++i < _nElements)
	{
		if (S[i] < min)
			min = S[i];
		if (S[i] > max)
			max = S[i];
	}
	return (max - min);
}

void Span::addMultipleNumber(int *n, unsigned int size)
{
	if (_nElements + size > N)
		throw(TooMuchElements());

	unsigned int i = 0;
	while (i < size)
	{
		S.push_back(n[i++]);
		_nElements++;
	}
}

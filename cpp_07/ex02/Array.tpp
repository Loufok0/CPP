template <typename T>
Array<T>::Array() : _arr(new T[0]()), _size(0)
{
	std::cout << "Array constructor called" << std::endl;
};

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n)
{
	unsigned int i = 0;
	while (i < n)
		_arr[i++] = 0;
	std::cout << "Array parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	if (this != &other)
	{
		_size = other.size();
		_arr = new T[_size]();
		unsigned int i = 0;
		while (i < _size)
			_arr[i++] = 0;
	}
	std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array &other)
{
	if (this != &other)
	{
		_size = other.size();
		_arr = new T[_size]();
		unsigned int i = 0;
		while (i < _size)
			_arr[i++] = 0;
	}
	std::cout << "Array copy assignation constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _arr;
	std::cout << "Array destructor called" << std::endl;
}

template <typename T>
int Array<T>::size() const
{
	return (_size);
}

template <typename T>
T& Array<T>::operator [] (size_t n)
{
	if (n >= _size)
		throw (OutOfBound());
	else
		return (_arr[n]);
}

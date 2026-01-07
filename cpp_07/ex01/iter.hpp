#pragma once

#include <iostream>
#include "colors.hpp"

template <typename T>
void	iter(T* arr, const int length, void (*f)(T* param))
{
	int i = 0;
	while (i < length)
		f(&arr[i++]);
}

//int array[i]

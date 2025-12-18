#pragma once

#include <iostream>
#include <cstring>
#include "stdlib.h"
#include <cmath>
#include <climits>
#include "./colors.hpp"


class ScalarConverter
{
	public:
		ScalarConverter(void);
		virtual ~ScalarConverter(void) = 0;

		static void convert(const std::string literal);
};

char getType(std::string literal);
void diplayInf(std::string literal);
void diplayNan(std::string literal);

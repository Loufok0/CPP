#pragma once
#include <iostream>
#include <stdlib.h>

class Base
{
	public:
		virtual ~Base(void);
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {};

Base* newA(void)
{
	Base* baseA = new A();
	return (baseA);
}

Base* newB(void)
{
	Base* baseB = new B();
	return (baseB);
}

Base* newC(void)
{
	Base* baseC = new C();
	return (baseC);
}

Base* generate(void)
{
	Base* (*f[3])(void) = {newA, newB, newC};
	int r = rand() % 3;
	return f[r]();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Base" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<Base&>(p);
		std::cout << "Base" << std::endl;
		return ;
	} catch (...) {}
}

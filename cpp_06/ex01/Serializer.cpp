#include "./Serializer.hpp"
		

Serializer::Serializer(void)
{
	std::cout << "Serializer constructer called" << std::endl;
};

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Serializer copy constructer called" << std::endl;
	(void)other;
};

Serializer& Serializer::operator = (const Serializer &other)
{
	std::cout << "Serializer copy assignement constructer called" << std::endl;
	(void)other;
	return (*this);
};

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructer called" << std::endl;
};

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}


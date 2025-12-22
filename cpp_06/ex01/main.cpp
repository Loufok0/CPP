#include "./Serializer.hpp"

int main(void)
{
	Data D;
	Data *TMP;
	uintptr_t tmp;

	D.value = 1234;
	std::cout << GREEN << "Untouched: " << RESET << std::endl
		<< "Address: " << &D << std::endl
		<< "Value:" << D.value
		<< std::endl;
	std::cout << std::endl << std::endl;


	tmp = Serializer::serialize(&D);
	std::cout << BLUE <<"Serialized: " << RESET << tmp << std::endl;;
	std::cout << "Serialized and casted: " << std::endl
		<< "Address:" << reinterpret_cast<Data*>(tmp) << std::endl
		<< "Value:" << reinterpret_cast<Data*>(tmp)->value << std::endl;
	std::cout << std::endl << std::endl;


	TMP = Serializer::deserialize(tmp);
	std::cout << GREEN << "Deserialized: " << RESET << std::endl
		<< "Address: " << TMP << std::endl
		<< "Value:" << TMP->value
		<< std::endl;
}

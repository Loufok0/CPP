#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <ctime>
#include "./colors.hpp"

#include <fstream>
#include <sstream>

class Btc
{
	private:
		std::string _input;
		std::string _data;

	public:
		Btc(void);
		Btc(std::string input, std::string data);
		~Btc(void);

		void printInput(void);
		void printData(void);

};

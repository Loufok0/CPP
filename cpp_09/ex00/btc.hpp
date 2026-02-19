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
		std::string _inputName;
		std::string _dataName;
		std::multimap<std::string, float> _input;
		std::multimap<std::string, float> _data;

	public:
		Btc(void);
		Btc(std::string input, std::string data);
		~Btc(void);

		void parseInput(void);
		void parseData(void);

		void printFile(std::string name);
		void printData(void);

};

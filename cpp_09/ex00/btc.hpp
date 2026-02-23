#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <ctime>
#include "./colors.hpp"

#include <fstream>
#include <sstream>


#define ss_m std::multimap<std::string, std::string>
#define ss_it ss_m::iterator

class Btc
{
	private:
		std::string _inputName;
		std::string _dataName;
		ss_m _input;
		ss_m _data;

	public:
		Btc(void);
		Btc(std::string input, std::string data);
		~Btc(void);

		void parseInput(void);
		void parseData(void);

		ss_it closestDate(std::string inputDate);
		void process(void);


		void printFile(std::string name);
		void printData(void);
};

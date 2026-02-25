#include "./btc.hpp"

Btc::Btc(void) : _inputName("./input.txt"), _dataName("./data.csv") {}
Btc::Btc(std::string input, std::string data) : _inputName(input), _dataName(data) {}

Btc::Btc(const Btc &other) {(void) other;}
Btc& Btc::operator = (const Btc &other)
{
	(void) other;
	return (*this);
}


Btc::~Btc(void) {}

void Btc::printFile(std::string name)
{
	std::ifstream file(name.c_str());
	std::string text;

	if (!file.is_open())
	{
		std::cout << ERROR << "Could not open file" << RESET << std::endl;
		return;
	}

	std::cout << BLUE << "READING FILE " << name << ":" << RESET << std::endl;

	while (std::getline(file, text))
	{
		std::cout << text << std::endl;
	}

	if (file.bad())
	{
		std::cout << ERROR << "Error while reading file" << RESET << std::endl;
	}

	std::cout << std::endl << std::endl;
}

void Btc::parseInput(void)
{
	std::ifstream	file(_inputName.c_str());
	std::string	line;

	while (std::getline(file, line))
	{
		size_t pos = line.find(" | ");

		if (pos == std::string::npos)
		{
			std::cout << ERROR << "Bad input => " << line << std::endl;
			continue;
		}

		std::string key = line.substr(0, pos);
		std::string value = line.substr(pos + 3);

		if (key == "date")
			continue;
		_input.insert(std::make_pair(key, value));
	}
}

void Btc::parseData(void)
{
	std::ifstream	file(_dataName.c_str());
	std::string	line;

	while (std::getline(file, line))
	{
		size_t pos = line.find(",");

		if (pos == std::string::npos)
		{
			std::cout << ERROR << "Bad input => " << line << std::endl;
			continue;
		}

		std::string key = line.substr(0, pos);
		std::string value = line.substr(pos + 1);

		if (key == "date")
			continue;
		_data.insert(std::make_pair(key, value));
	}
}


void Btc::printData(void)
{
	ss_it it1 = _input.begin();
	while (it1 != _input.end())
	{
		std::cout << it1->first << " :::::::: " << it1->second << std::endl;
		it1++;
	}

	ss_it it2 = _data.begin();
	while (it2 != _data.end())
	{
		std::cout << it2->first << " :::::::: " << it2->second << std::endl;
		it2++;
	}

}

int dateToInt(const std::string &date)
{
	int res = std::atoi((date.substr(0,4) +
				date.substr(5,2) +
				date.substr(8,2)).c_str());
	return (res);
}


bool isLeapYear(int year)
{
	if (year % 400 == 0)
		return (true);
	if (year % 100 == 0)
		return (false);
	return (year % 4 == 0);
}

int daysInMonth(int y, int m)
{
	switch (m)
	{
		case 1: case 3: case 5: case 7:
		case 8: case 10: case 12:
			return (31);

		case 4: case 6: case 9: case 11:
			return (30);

		case 2:
			return (isLeapYear(y) ? 29 : 28);

		default:
			return (-1); // invalid date
	}
}

bool validDate(std::string date)
{
	if (date.size() != 10)
	{
		std::cout << ERROR << "Invalid date ( " << date << " )" << std::endl;
		return (false);
	}
	int y = std::atoi(date.substr(0,4).c_str());
	int m = std::atoi(date.substr(5,2).c_str());
	int d = std::atoi(date.substr(8,2).c_str());

	if (y < 2000 || y > 2050)
	{
		std::cout << ERROR << "Invalid yeay ( " << date << " )" << std::endl;
		return (false);
	}
	if (m < 1 || m > 12)
	{
		std::cout << ERROR << "Invalid month ( " << date << " )" << std::endl;
		return (false);
	}
	if (d < 1 || d > daysInMonth(y, m))
	{
		std::cout << ERROR << "Invalid day ( " << date << " )" << std::endl;
		return (false);
	}
	return (true);
}

bool is_number(const std::string& s)
{
	int count = 0;
	std::string::const_iterator it = s.begin();
	while (it != s.end() && (std::isdigit(*it) || *it == '.'))
	{
		if (*it == '.')
			count++;
		if (count > 1)
			return (false);
		it++;
	}
	return (!s.empty() && it == s.end());
}

bool validNumber(std::string n)
{

	if (!is_number(n))
	{
		std::cout << ERROR << "Not a number ( " << n << " )" << std::endl;
		return (false);
	}

	std::stringstream ss(n);
	float f;
	ss >> f;
	if (f < 0)
	{
		std::cout << ERROR << "Number too small ( " << n << " )" << std::endl;
		return (false);
	}
	else if (f > 100)
	{
		std::cout << ERROR << "Number too large ( " << n << " )" << std::endl;
		return (false);
	}
	else
		return (true);
}

unsigned int abs_2f(float n1, float n2)
{
	unsigned int abs_diff = n1 > n2 ?
		(unsigned int)n1 - (unsigned int)n2 :
		(unsigned int)n2 - (unsigned int)n1;

	return (abs_diff);
}

ss_it Btc::closestDate(std::string inputDate)
{
	ss_it it = _data.lower_bound(inputDate);

	// Case 1: exact match
	if (it != _data.end() && it->first == inputDate)
		return it;

	// Case 2: inputDate is before first element
	if (it == _data.begin())
		return it;

	// Case 3: inputDate is after last element
	if (it == _data.end())
	{
		--it;
		return it;
	}

	// Case 4: between two dates
	ss_it next = it;
	ss_it prev = --it;

	int input = dateToInt(inputDate);
	int d1 = std::abs(dateToInt(prev->first) - input);
	int d2 = std::abs(dateToInt(next->first) - input);

	return (d1 <= d2) ? prev : next;
}

void Btc::process(void)
{
	std::cout << BLUE << "OUT: " << RESET << std::endl;
	ss_it it = _input.begin();

	while (it != _input.end())
	{
		ss_it tmp = closestDate(it->first);
		if (tmp != _data.end())
		{
			if (!validDate((it->first)) || !validNumber(it->second))
			{
				it++;
				continue;
			}

			std::stringstream ss1(it->second);
			float f1;
			ss1 >> f1;
	
			std::stringstream ss2(tmp->second);
			float f2;
			ss2 >> f2;
			std::cout << it->first << " => " << it->second << " = " << f1 * f2 << std::endl;
		}
		else
			std::cout << ERROR << "Date not found: " << it->first << std::endl;

		++it;
	}
}

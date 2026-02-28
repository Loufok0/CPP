#include "./RPN.hpp"

RPN::RPN(void) : _rpn("1 1 +") {}
RPN::RPN(std::string rpn) : _rpn(rpn) {}
RPN::RPN(const RPN& other) {(void)other;}
RPN& RPN::operator =(const RPN& other) {(void)other; return (*this);}
RPN::~RPN(void) {}

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

bool is_operator(std::string tmp)
{
	static const std::string op = "+-/*";

	if (op.find(tmp[0]) == std::string::npos)
		return (false);
	return (true);
}

long int RPN::eval(void)
{
	size_t prev = 0;
	size_t pos = 0;
	long int res = 0;
	while ((pos = _rpn.find(" ", prev)) != std::string::npos)
	{
		if (pos == std::string::npos)
		{
			std::cout << ERROR << "Error in input" << std::endl;
			return (-1);
		}

		std::string tmp = _rpn.substr(prev, pos);
		if (is_number(tmp))
		{
			std::stringstream ss(tmp);
			long int i;
			ss >> i;

			_s.push(i);
			prev = pos + 1;
		}
		else if (is_operator(tmp.substr(pos - 1)))
		{
			if (_s.size() < 2)
			{
				std::cout << ERROR << "Not enough numbers before operand " << tmp << std::endl;
				return (-1);
			}

			long int s_z = _s.top();
			_s.pop();
			switch(tmp[0] - 57) {
				case 0:
					res = s_z / _s.top();
					prev = pos + 1;
					break;
				case 2:
					res = s_z - _s.top();
					prev = pos + 1;
					break;
				case 4:
					res = s_z + _s.top();
					prev = pos + 1;
					break;
				case 5:
					res = s_z * _s.top();
					prev = pos + 1;
					break;
				default:
					std::cout << ERROR << "Operator swich case problem:" << tmp << std::endl;
					return (-1);
			}
			_s.pop();
			_s.push(res);
			prev = pos + 1;
		}
		else
		{
			std::cout << ERROR << "END" << _s.top() << std::endl;
			return (_s.top());
		}
	}	
	return (_s.top());
}


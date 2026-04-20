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

bool is_operator(std::string& tmp)
{
	static const std::string op = "+-/*";

	if (op.find(tmp[0]) == std::string::npos)
		return (false);
	return (true);
}

void RPN::eval(void)
{
	size_t prev = 0;
	size_t pos = 0;
	long int res = 0;
	do
	{
		pos = _rpn.find(" ", prev);
		std::string tmp = _rpn.substr(prev, pos - prev);
		if (is_number(tmp))
		{
			std::stringstream ss(tmp);
			long int i;
			ss >> i;

			_s.push(i);
			prev = pos + 1;
		}
		else if (is_operator(tmp))
		{
			if (_s.size() < 2)
			{
				std::cout << ERROR << "Not enough numbers before operand " << tmp << std::endl;
				return;
			}

			long int s_z = _s.top();
			_s.pop();
			switch(tmp[0]) {
				case '/':
					res = _s.top() / s_z;
					prev = pos + 1;
					break;
				case '-':
					res = _s.top() - s_z;
					prev = pos + 1;
					break;
				case '+':
					res = _s.top() + s_z;
					prev = pos + 1;
					break;
				case '*':
					res = _s.top() * s_z ;
					prev = pos + 1;
					break;
				default:
					std::cout << ERROR << "Operator swich case problem: '" << tmp << "'" << std::endl;
					return;
			}
			_s.pop();
			_s.push(res);
			prev = pos + 1;
		}
		else if (pos == std::string::npos)
			continue;
		else if (tmp == "")
		{
			prev = pos + 1;
			continue;
		}
		else
		{
			std::cout << ERROR << "Non wanted character: \"" << tmp << "\"" << std::endl;
			return;
		}
	}	
	while (pos != std::string::npos);
	std::cout << GREEN << "RESULT: " << _s.top() << std::endl;

	return;
}


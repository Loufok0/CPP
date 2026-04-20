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

	if (tmp.size() > 1)
		return (false);

	if (op.find(tmp[0]) == std::string::npos)
		return (false);
	return (true);
}

void RPN::eval(void)
{
	size_t prev = 0;
	size_t pos = 0;
	long int res = 0;
	int last = 0;
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
			last = i;
			prev = pos + 1;
		}
		else if (is_operator(tmp))
		{
			if (_s.size() < 2)
			{
				std::cerr << ERROR << "Not enough numbers before operand " << tmp << std::endl;
				return;
			}

			long int s_z = _s.top();
			_s.pop();
			switch(tmp[0]) {
				case '/':
					if (s_z == 0)
					{
						std::cerr << ERROR << "Division by zero" << std::endl;
						return;
					}
					res = _s.top() / s_z;
					break;
				case '-':
					res = _s.top() - s_z;
					break;
				case '+':
					res = _s.top() + s_z;
					break;
				case '*':
					res = _s.top() * s_z ;
					break;
				default:
					std::cerr << ERROR << "Operator swich case problem: '" << tmp << "'" << std::endl;
					return;
			}
			_s.pop();
			_s.push(res);
			prev = pos + 1;
		}
		else if (tmp == "")
		{
			prev = pos + 1;
			continue;
		}
		else
		{
			std::cerr << ERROR << "Non wanted character: \"" << tmp << "\"" << std::endl;
			return;
		}
	}	
	while (pos != std::string::npos);
	if (_s.size() != 1)
	{
		std::cerr << ERROR << "Invalid RPN expression, too many remaining numbers in the stack (stack size = " << _s.size() << "), you probably put too much numbers, you may tryna add less of them in order to make it work... yeah, after a long reflexion i think you may need to remove some of them, you may begin by the last one for example, the " << last << ", good luck, you can do it! " << std::endl;
		return;
	}

	std::cout << GREEN << "RESULT: " << _s.top() << std::endl;

	return;
}


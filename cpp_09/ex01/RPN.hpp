#include <iostream>
#include <stack>
#include <sstream>
#include "./colors.hpp"

#define s_it std::deque::iterator

class RPN
{
	private:
		std::string _rpn;
		std::stack<long int> _s;
	
	public:
		RPN(void);
		RPN(std::string rpn);
		RPN(const RPN& other);
		RPN& operator =(const RPN& other);
		~RPN(void);

		long int eval(void);

};

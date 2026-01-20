#include "./Span.hpp"


int main(void)
{
	Span S = Span(10);
	S.addNumber(-10);
	S.addNumber(2);
	int N[] = {7, 70, 700};
	S.addMultipleNumber(N, sizeof(N)/sizeof(N[0]));

	int i = 0;
	std::cout << "Span contain:" << std::endl;
	while (i < 5)
		std::cout << S[i++] << std::endl;
	std::cout << std::endl;
	std::cout << "Shortest Span: " << S.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << S.longestSpan() << std::endl;
}

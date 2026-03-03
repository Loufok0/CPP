#include "./MutantStack.hpp"

int main()
{
	std::cout << "=== Basic stack test ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\n=== Iteration test ===" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n=== Const iteration test ===" << std::endl;

	const MutantStack<int> constStack(mstack);
	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();

	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	std::cout << "\n=== Comparison with std::stack ===" << std::endl;

	std::stack<int> s(mstack);
	std::cout << "std::stack size: " << s.size() << std::endl;

	std::cout << "\n=== String test ===" << std::endl;

	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("Mutant");
	stringStack.push("Stack");

	for (MutantStack<std::string>::iterator sit = stringStack.begin();
		 sit != stringStack.end();
		 ++sit)
	{
		std::cout << *sit << std::endl;
	}

	return 0;
}










/*
int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "it: " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl << std::endl;
	}
	{
		MutantStack<int, std::vector<int> > mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int, std::vector<int> >::const_iterator it = mstack.begin();
		MutantStack<int, std::vector<int> >::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "it: " << *it << std::endl;
			++it;
		}
		std::stack<int, std::vector<int> > s(mstack);
		std::cout << std::endl << std::endl;
	}
	return 0;

}

*/

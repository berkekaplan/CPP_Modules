#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "********************"	<< std::endl;

	Span sp2 = Span(10000);
	std::vector<int> numbers;
	for (int i = 1; i <= 10000; i++)
		numbers.push_back(i);
	sp2.fill(numbers.begin(), numbers.end());
	sp2.print();

	return 0;
}
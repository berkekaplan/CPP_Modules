#include "PmergeMe.hpp"
int main(int ac, char **av)
{

	try
	{
		ac--;
		av++;
		PmergeMe::checkArg(ac, av);
		PmergeMe::setContainers(ac, av);
		PmergeMe::sortListContainer();
		PmergeMe::sortVectorContainer();
	}
	catch ( std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		Bitcoin::checkArg(ac, av);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

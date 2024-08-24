#include "RPN.hpp"

int main(int argc, char **argv){

	try
	{
		RPN::checkArg(argc, argv);
		RPN::printRPN();
	}
	catch ( std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

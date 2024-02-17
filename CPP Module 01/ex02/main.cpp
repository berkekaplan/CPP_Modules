#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "&String-> " << &brain << std::endl;
	std::cout << "stringPTR-> " << stringPTR << std::endl;
	std::cout << "&stringREF-> " << &stringREF << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "String-> " << brain << std::endl;
	std::cout << "*stringPTR-> " << *stringPTR << std::endl;
	std::cout << "stringREF-> " << stringREF << std::endl;
	return (0);
}
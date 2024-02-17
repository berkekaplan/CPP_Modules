#include "Harl.hpp"

int	main()
{
	Harl harl;
	std::string	level;

	while (1)
	{
		std::cout << "Write level: DEBUG, INFO, WARNING, ERROR, EXIT(For finish program)" << std::endl;
		std::getline(std::cin, level);
		
		if (!level.compare("EXIT"))
			return (0);
		
		else if (!level.compare("DEBUG") || !level.compare("INFO") || !level.compare("WARNING") || !level.compare("ERROR"))
			harl.complain(level);
		
		else
			std::cout << "Wrong level choise, try again." << std::endl;
	}
	return 0;
}
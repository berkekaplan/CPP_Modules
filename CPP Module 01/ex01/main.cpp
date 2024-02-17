#include "Zombie.hpp"

int	main()
{
	Zombie		*arrayZombies;
	std::string	nameZombies;
	int			numberZombies;
	
	std::cout << "Welcome!, let's create a Zombie array!" << std::endl;
	std::cout << "Enter the number of Zombie to create: " << std::endl;
	std::cin >> numberZombies;
	std::cout << "Zombie names: ";
	std::cin >> nameZombies;
	arrayZombies = zombieHorde(numberZombies, nameZombies);
	for (int i = 0; i < numberZombies; i++)
		arrayZombies[i].announce();
	delete[] arrayZombies;
	return 0;
}

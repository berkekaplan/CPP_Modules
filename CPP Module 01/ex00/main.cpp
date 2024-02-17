#include "Zombie.hpp"

int	main()
{
	std::string	zombieName;

	std::cout << "Welcome!" << std::endl;
	std::cout << "We are creating Zombie from Stack" << std::endl;
	std::cout << "Enter Zombie name: ";
	std::getline(std::cin, zombieName);
	Zombie	stackZombie(zombieName);
	stackZombie.announce();

	std::cout << "We are creating Zombie from Heap" << std::endl;
	std::cout << "Enter Zombie name: ";
	std::getline(std::cin, zombieName);
	Zombie	*heapZombie = newZombie(zombieName);
	heapZombie->announce();
	delete	heapZombie;

	std::cout << "Creating randomChump(name)" << std::endl;
	randomChump("randomZombie");
	return (0);
}

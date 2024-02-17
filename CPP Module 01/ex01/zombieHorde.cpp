#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*arrayZombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		arrayZombie[i].setName(name + std::to_string(i));
	return (arrayZombie);
}

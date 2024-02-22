#include "ClapTrap.hpp"

int main()
{
    ClapTrap c1("C1");
    ClapTrap c2("C2");
    c2.takeDamage(100);
    c2.beRepaired(10);

    c1.beRepaired(10);
    c1.beRepaired(10);

    for(int i = 0; i < 10; i++)
        c1.attack("grenade");
}
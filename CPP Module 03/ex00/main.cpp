#include "ClapTrap.hpp"

int main()
{
    ClapTrap c1("SOVA");
    ClapTrap c2("JETT");
    c2.takeDamage(100);
    c2.beRepaired(10);

    c1.beRepaired(10);
    c1.beRepaired(10);

    for(int i = 0; i < 10; i++)
        c1.attack("Valorant Ulti Fight");
}
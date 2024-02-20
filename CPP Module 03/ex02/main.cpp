#include "FragTrap.hpp"

int main()
{
    FragTrap a("test1");
    FragTrap b("test2");
    
    b.attack("FİRE!");
    b.takeDamage(10);
    b.beRepaired(10);

    b.highFivesGuys();
    a.highFivesGuys();
}

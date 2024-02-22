#include "ScavTrap.hpp"
int main()
{
    ClapTrap b("Braum");
    ScavTrap a("Ashe");
    b.attack("Greanade");
    b.takeDamage(10);
    b.beRepaired(10);
    a.attack("Knife");
    a.takeDamage(10);
    a.beRepaired(10);
    a.guardGate();
}
#include "ScavTrap.hpp"
int main()
{
    ClapTrap b("Miss Fortune");
    ScavTrap a("Lux");
    b.attack("Guardian_Angel");
    b.takeDamage(10);
    b.beRepaired(10);
    a.attack("Tear_of_the_Goddess");
    a.takeDamage(10);
    a.beRepaired(10);
    a.guardGate();
}
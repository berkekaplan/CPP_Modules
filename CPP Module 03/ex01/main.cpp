#include "ScavTrap.hpp"

int main()
{
    ClapTrap b("Clap");
    ScavTrap a("Scav");
   
    b.attack("Scav");
    b.takeDamage(10);
    b.beRepaired(10);
    
    a.attack("Clap");
    a.takeDamage(10);
    a.beRepaired(10);
    
    a.guardGate();
}
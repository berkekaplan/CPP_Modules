#include "ClapTrap.hpp"

int main()
{
    ClapTrap c1("C1");
    ClapTrap c2("C2");
    
    c1.attack("C2");
    c1.takeDamage(10);
    c1.beRepaired(10);
    
    c2.attack("C1");
    c2.takeDamage(1);
    c2.beRepaired(10);

}
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("CT Player");
    ScavTrap scavTrap("ST Player");

	std::cout << "----------------------------------------------------" << std::endl;
	clapTrap.beRepaired(5);
    clapTrap.takeDamage(10);
    clapTrap.attack("ST Player");

	std::cout << "----------------------------------------------------" << std::endl;
    scavTrap.attack("CT Player");
    scavTrap.beRepaired(5);
    scavTrap.takeDamage(10);
    scavTrap.guardGate();

	std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}

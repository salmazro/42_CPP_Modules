#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clapTrap("CT Player");
    ScavTrap scavTrap("ST Player");
    FragTrap fragTrap("FT Player");

	std::cout << "----------------------------------------------------" << std::endl;
	clapTrap.beRepaired(5);
    clapTrap.takeDamage(10);
    clapTrap.attack("ST Player");

	std::cout << "----------------------------------------------------" << std::endl;
    scavTrap.attack("FT Player");
    scavTrap.beRepaired(5);
    scavTrap.takeDamage(10);
    scavTrap.guardGate();

	std::cout << "----------------------------------------------------" << std::endl;
    fragTrap.attack("CT Player");
    fragTrap.beRepaired(5);
    fragTrap.takeDamage(10);
    fragTrap.highFivesGuys();

	std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}

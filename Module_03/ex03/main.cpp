#include "DiamondTrap.hpp"

int main()
{
    ClapTrap clapTrap("CT Player");
	DiamondTrap diamondTrap("DT Player");

	std::cout << "----------------------------------------------------" << std::endl;
	clapTrap.beRepaired(5);
    clapTrap.takeDamage(10);
    clapTrap.attack("DT Player");

	diamondTrap.attack("CT Player");
	diamondTrap.beRepaired(5);
	diamondTrap.takeDamage(10);
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();
	diamondTrap.whoAmI();

	std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}

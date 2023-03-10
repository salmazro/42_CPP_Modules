#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("CT Player");
    ClapTrap clapTrap2(clapTrap);
    ClapTrap clapTrap3 = clapTrap2;

	std::cout << "----------------------------------------------------" << std::endl;
	clapTrap.beRepaired(5);
    clapTrap.takeDamage(10);
    clapTrap.attack("CT Player");

	std::cout << "----------------------------------------------------" << std::endl;
    clapTrap2.beRepaired(5);
    clapTrap2.attack("enemy");
    clapTrap2.takeDamage(10);

	std::cout << "----------------------------------------------------" << std::endl;
    clapTrap3.attack("enemy");
    clapTrap3.takeDamage(10);
    clapTrap3.beRepaired(5);

	std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}

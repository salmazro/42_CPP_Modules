#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	zero("zer0");
	ClapTrap	hammer("sir Hammerlock");
	ClapTrap	hand(zero);
	ClapTrap	sir("");

	sir = hammer;

	zero.attack("minion");
	hammer.attack("car");
	hand.attack("minion");
	sir.attack("hulk");

	zero.takeDamage(6);
	zero.beRepaired(1);

	return (0);
}

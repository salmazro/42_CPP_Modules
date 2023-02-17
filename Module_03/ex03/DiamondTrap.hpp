# ifndef DIAMONDTRAP
# define DIAMONDTRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(DiamondTrap& dt);
		DiamondTrap& operator=(DiamondTrap& dt);
		~DiamondTrap();
		void attack(const std::string& target);
		void whoAmI();
};

#endif

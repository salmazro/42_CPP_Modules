# ifndef SCAVTRAP
# define SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(ScavTrap& st);
		ScavTrap& operator=(ScavTrap& st);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate(void);
};

#endif

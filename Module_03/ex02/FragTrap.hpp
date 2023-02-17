# ifndef FRAGTRAP
# define FRAGTRAP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(FragTrap& ft);
		FragTrap& operator=(FragTrap& ft);
		~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys(void);

};

#endif

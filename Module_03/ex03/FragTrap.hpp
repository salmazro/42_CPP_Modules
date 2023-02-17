# ifndef FRAGTRAP
# define FRAGTRAP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(FragTrap& ft);
		FragTrap& operator=(FragTrap& ft);
		~FragTrap();
		void attack(const std::string& target);
		void sethitpoint(int hit);
		int gethitpoint( void ) const ;
		void highFivesGuys(void);

};

#endif

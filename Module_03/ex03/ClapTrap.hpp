# ifndef CLAP_TRAP
# define CLAP_TRAP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int hitPoints;
		int	energyPoints;
		int attackDamage;



	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& ct);
		ClapTrap& operator=(ClapTrap& ct);
		~ClapTrap();
		void setname(std::string n);
		std::string getname();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif

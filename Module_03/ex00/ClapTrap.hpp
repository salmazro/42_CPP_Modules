#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string n);
		ClapTrap(ClapTrap& ct);
		~ClapTrap();

		void setname(std::string n);
		std::string getname();

		ClapTrap& operator=(ClapTrap& ct);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif

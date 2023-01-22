# ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *wp;

	public:
		HumanB(std::string temp);
		~HumanB();
		void attack();
		void setWeapon(Weapon &wp);
};

# endif

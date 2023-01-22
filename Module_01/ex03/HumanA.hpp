# ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &wp;

	public:
		HumanA(std::string temp, Weapon &weapon);
		~HumanA();
		void attack();
};

# endif

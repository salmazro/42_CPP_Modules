# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		~Weapon();
		Weapon(std::string W_name);
		void setType(std::string t);
		const std::string &getType(void);
};

# endif

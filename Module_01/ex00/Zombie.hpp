# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void set_name(std::string n);
		std::string get_name(void);
		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

# endif

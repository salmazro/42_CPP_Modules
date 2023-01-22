#include "Zombie.hpp"

void Zombie::set_name(std::string n)
{
	this->name = n;
}

std::string Zombie::get_name(void)
{
	return (name);
}

// constructor
Zombie::Zombie()
{
}

// destructor
Zombie::~Zombie()
{
	std::cout << "Kill Zombie: " << get_name() << std::endl;
}

void Zombie::announce(void)
{
	std::cout << Zombie::get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



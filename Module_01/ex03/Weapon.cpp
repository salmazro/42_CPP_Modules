#include "Weapon.hpp"

// constructor
Weapon::Weapon()
{
}

// destructor
Weapon::~Weapon()
{
}

Weapon::Weapon(std::string W_name)
{
	this->setType(W_name);
}

void Weapon::setType(std::string t)
{
	this->type = t;
}

const std::string &Weapon::getType(void)
{
	return(this->type);
}

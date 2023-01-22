#include "HumanB.hpp"

HumanB::HumanB(std::string temp)
{
	this->name = temp;
	this->wp = NULL;
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	std::cout << name << " uses " << this->wp->getType() << " as their weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &wp)
{
	this->wp = &wp;
}

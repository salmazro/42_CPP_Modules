#include "HumanA.hpp"

HumanA::HumanA(std::string temp, Weapon &weapon):wp(weapon)
{
	this->name = temp;
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << name << " uses " << this->wp.getType() << " as their weapon" << std::endl;
}

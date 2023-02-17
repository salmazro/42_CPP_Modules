#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "ScavTrap overload constructor called" << std::endl;
	this->setname(name);
	this->getname();
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap& st)
{
	std::cout << "ScavTrap copy constructor has been called" << std::endl;
	*this = st;
}
ScavTrap& ScavTrap::operator=(ScavTrap& st)
{
	std::cout << "ScavTrap copy assigment operator has been called" << std::endl;
	this->name = st.name;
	this->hitPoints = st.hitPoints;
	this->energyPoints = st.energyPoints;
	this->attackDamage = st.attackDamage;
	return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has been called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->getname() << " attacks " << target << ", causing ";
		std::cout <<  this->attackDamage << " points of damage!" << std::endl;
		this->hitPoints--;
	}
	else
		std::cout << "ScavTrap is low on energy "<< std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

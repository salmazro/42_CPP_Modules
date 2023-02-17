#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	this->setname(name);
	this->getname();
	std::cout << "FragTrap overload constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap& ft)
{
	std::cout << " FragTrap copy constructor has been called" << std::endl;
	*this = ft;
}
FragTrap& FragTrap::operator=(FragTrap& ft)
{
	std::cout << "FragTrap copy assigment operator has been called" << std::endl;
	this->name = ft.name;
	this->hitPoints = ft.hitPoints;
	this->energyPoints = ft.energyPoints;
	this->attackDamage = ft.attackDamage;
	return (*this);
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor has been called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if(this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "FragTrap " << this->getname() << " attacks " << target << ", causing ";
		std::cout <<  this->attackDamage << " points of damage!" << std::endl;
		this->hitPoints--;
	}
	else
		std::cout << "FragTrap is low on energy "<< std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap"<< this->name << "gives a high five to you" << std::endl;
}

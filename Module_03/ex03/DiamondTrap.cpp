#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond-Default_clap_name"), name("DaimontDefault")
{
	std::cout << "DiamondTrap default constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << "DiamondTrap overload constructor called" << std::endl;
	this->hitPoints = FragTrap::gethitpoint();
	this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = this->ScavTrap::attackDamage;
}


DiamondTrap::DiamondTrap(DiamondTrap& dt)
{
	std::cout << " DiamondTrap copy constructor has been called" << std::endl;
	*this = dt;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap& dt)
{
	std::cout << "DiamondTrap copy assigment operator has been called" << std::endl;
	this->name = dt.name;
	this->hitPoints = dt.hitPoints;
	this->energyPoints = dt.energyPoints;
	this->attackDamage = dt.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor has been called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack( target );
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "DiamondTrap orginated from ClapTrap: " << this->getname() << std::endl;

}


#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->setname(name);
	this->getname();
	std::cout << "ClapTrap overload constructor has been called" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 4;

}
ClapTrap::ClapTrap(ClapTrap& ct)
{
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	*this = ct;
}
ClapTrap& ClapTrap::operator=(ClapTrap& ct)
{
	std::cout << "ClapTrap copy assigment operator has been called" << std::endl;
	this->name = ct.name;
	this->hitPoints = ct.hitPoints;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor has been called" << std::endl;
}

void ClapTrap::setname(std::string n)
{
	this->name = n;
}
std::string ClapTrap::getname()
{
	return (this->name);
}
void ClapTrap::attack(const std::string& target)
{
	if(this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->getname() << " attacks " << target << ", causing ";
		std::cout <<  this->attackDamage << " points of damage!" << std::endl;
		this->hitPoints--;
	}
	else
		std::cout << "ClapTrap is low on energy "<< std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	int hit = amount;
	while (amount && (this->hitPoints >= 0) && (this->energyPoints >= 0))
	{
		amount--;
		this->hitPoints--;
		this->energyPoints--;

	}
	std::cout << this->name << " takes " << hit << " of damage \n"
			<< "remaining health: " << this->hitPoints << std::endl;

}
void ClapTrap::beRepaired(unsigned int amount)
{
	int repaired = amount;
	while(amount && this->hitPoints >= 10)
	{
		this->hitPoints++;
		amount--;
	}
	std::cout << this->name << " is being repaired " << repaired << " to increase its health -> "
		<< this->hitPoints << std::endl;
}

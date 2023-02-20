#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
	this->brain  = new Brain();
	std::cout << "WrongDog default constructor  is called" << std::endl;
}

WrongDog::WrongDog(WrongDog& wd) : WrongAnimal()
{
	*this = wd;
	this->brain = new Brain(*wd.getBrain());
}

WrongDog& WrongDog::operator=(WrongDog & wd)
{
	if(this != &wd)
	{
		this->~WrongDog();
		this->brain = new Brain(*wd.getBrain());
		this->WrongAnimal::operator=(wd);
	}
	return (*this);
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor is called" << std::endl;
	//this->brain;
}

void WrongDog::makeSound() const
{
	std::cout << "How How" << std::endl;
}

Brain *WrongDog::getBrain() const
{
	return (this->brain);
}

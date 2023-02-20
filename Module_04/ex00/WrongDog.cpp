#include "WrongDog.hpp"

WrongDog::WrongDog(): WrongAnimal("WrongDog")
{
	std::cout << "WrongDog default constructor  is called" << std::endl;
}

WrongDog::WrongDog(WrongDog& wd) : WrongAnimal()
{
	*this = wd;
}

WrongDog& WrongDog::operator=(WrongDog & wd)
{
	if(this != &wd)
		this->type = wd.type;
	return (*this);;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor is called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "How How" << std::endl;
}

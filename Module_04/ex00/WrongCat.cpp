#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor  is called" << std::endl;
}

WrongCat::WrongCat(WrongCat& wc) : WrongAnimal()
{
	*this = wc;
}

WrongCat& WrongCat::operator=(WrongCat & wc)
{
	if(this != &wc)
		this->type = wc.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	this->brain  = new Brain();
	std::cout << "WrongCat default constructor  is called" << std::endl;
}

WrongCat::WrongCat(WrongCat& wc) : WrongAnimal()
{
	*this = wc;
	this->brain = new Brain(*wc.getBrain());
}

WrongCat& WrongCat::operator=(WrongCat & wc)
{
	if(this != &wc)
	{
		this->~WrongCat();
		this->brain = new Brain(*wc.getBrain());
		this->WrongAnimal::operator=(wc);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
	//this->brain;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain *WrongCat::getBrain() const
{
	return (this->brain);
}

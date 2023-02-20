#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor  is called" << std::endl;
	this->brain =new Brain();
}

Cat::Cat(Cat& c) : Animal()
{
	// *this = c;
	this->brain = new Brain(*c.getBrain());
}

Cat& Cat::operator=(Cat & c)
{
	if(this != &c)
	{
		this->~Cat();
		this->brain = new Brain(*c.getBrain());
		this->Animal::operator=(c);
	}
	return (*this);
}

Cat::~Cat()
{
	// this->brain->~Brain();
	delete brain;
	std::cout << "Cat destructor is called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}

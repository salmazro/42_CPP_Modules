#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor  is called" << std::endl;
}

Cat::Cat(Cat& c) : Animal()
{
	*this = c;
}

Cat& Cat::operator=(Cat & c)
{
	if(this != &c)
		this->type = c.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

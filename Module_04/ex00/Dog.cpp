#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor  is called" << std::endl;
}

Dog::Dog(Dog& d) : Animal()
{
	*this = d;
}

Dog& Dog::operator=(Dog & d)
{
	if(this != &d)
		this->type = d.type;
	return (*this);;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "How How" << std::endl;
}

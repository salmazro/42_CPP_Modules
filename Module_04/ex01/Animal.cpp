#include "Animal.hpp"

Animal::Animal() : type("Butterfly")
{
	std::cout << "Animal default constructor  is called" << std::endl;
}

Animal::Animal(Animal& a)
{
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = a;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "Animal overload constructor has been called" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

Animal& Animal::operator=(Animal & a)
{
	std::cout << "Animal copy assigment operator has been called" << std::endl;
	if(this != &a)
		this->type = a.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Click Click" << std::endl;
}

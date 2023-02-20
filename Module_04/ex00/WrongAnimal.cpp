#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Monkey")
{
	std::cout << "WrongAnimal default constructor  is called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& wa)
{
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
	*this = wa;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
	std::cout << "WrongAnimal overload constructor has been called" << std::endl;
	this->type = _type;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal & wa)
{
	std::cout << "WrongAnimal copy assigment operator has been called" << std::endl;
	if(this != &wa)
		this->type = wa.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor is called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Click Click" << std::endl;
}

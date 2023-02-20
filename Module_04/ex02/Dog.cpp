#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor  is called" << std::endl;
	this->brain =new Brain();
}

Dog::Dog(Dog& d) : Animal(d)
{
	// *this = d;
	this->brain =new Brain(*d.getBrain());
}

Dog& Dog::operator=(Dog & d)
{
	if(this != &d)
	{
		this->~Dog();
		this->brain = new Brain(*d.getBrain());
		this->Animal::operator=(d);
	}
	return (*this);;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor is called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "How How" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}

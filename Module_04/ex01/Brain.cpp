#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor has been called" << std::endl;
}

Brain::Brain(Brain& b)
{
	*this = b;
}

Brain& Brain::operator=(Brain const &b)
{
	int i = 0;
	while (i < 100)
	{
		this->idea[i] = b.idea[i];
		i++;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor has been called" << std::endl;
}

void Brain::ideaGeneration(int i, std::string idea)
{
	this->idea[i] = idea;

}

std::string const  &Brain::getIdea (int i) const
{

	return (this->idea[i]);
}


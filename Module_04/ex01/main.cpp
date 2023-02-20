#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"


int main()
{
	Animal *Animal[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			Animal[i] = new Cat();
		else
			Animal[i] = new Dog();
		Animal[i]->makeSound();
		std::cout << "----------------------------------------------------------" << std::endl;
	}

	for (int i = 0; i < 6; i++)
	{
		delete Animal[i];
	}
	std::cout << "----------------------------------------------------------" << std::endl;

	Dog Dalmatian;
	Dog Perdita = Dalmatian;
	std::cout << "----------------------------------------------------------" << std::endl;

	for (int i = 0; i < 50; ++i)
	{
		Dalmatian.getBrain()->ideaGeneration(i, "Run from Cruella\n");
		Perdita.getBrain()->ideaGeneration(i, "Fight Cruella\n");
	}
	std::cout << Dalmatian.getBrain()->getIdea(3);
	std::cout << Perdita.getBrain()->getIdea(3);
	std::cout << "----------------------------------------------------------" << std::endl;
}

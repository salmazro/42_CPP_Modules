#include "Zombie.hpp"

int main(void)
{
	// test case 1 with user input:
	/*Zombie *obj;
	std::string temp;
	std::cout << "Enter Zombie name: ";
	std::cin >> temp;
	obj = newZombie(temp);
	obj->announce();
	std::cout << "Zombie is in heap" << std::endl;
	std::cout << "Enter Zombie name: ";
	std::cin >> temp;
	randomChump(temp);
	delete obj;
	return (0);*/

	// test case 2 without user input:
	Zombie *obj = newZombie("Shama");
	obj->announce();
	randomChump("Almaz");
	delete obj;
	return (0);
}

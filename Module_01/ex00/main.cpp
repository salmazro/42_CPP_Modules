#include "Zombie.hpp"

int main(void)
{
	Zombie *obj;
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
	return (0);
}

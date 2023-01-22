#include "Zombie.hpp"

int main(void)
{
	Zombie *obj = zombieHorde(3, "Shama");
	for (int i = 0; i < 3; i++)
		obj[i].announce();
	delete[] obj;
	return (0);
}

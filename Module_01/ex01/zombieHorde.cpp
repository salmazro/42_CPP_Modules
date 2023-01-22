#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *num = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		num[i].set_name(name);
		i++;
	}
	return(num);
}

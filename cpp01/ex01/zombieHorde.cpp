#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{
	int		i;
	Zombie*	horde;

	horde = new Zombie[N];
	for (i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
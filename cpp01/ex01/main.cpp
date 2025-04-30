#include "Zombie.hpp"

bool isNumeric(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

int main(void)
{
	int			N;
	std::string	name;
	Zombie*		horde;

	std::cout << "Enter the number of zombies: ";
	std::cin >> N;
	if (std::cin.fail() || N <= 0) {
		std::cerr << "Invalid number of zombies." << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << "Enter the name of the zombies: ";
	std::cin >> name;
	horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (EXIT_SUCCESS);
}
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
	Zombie* zombie;
	std::string name;
	std::string mem;

	name = "";
	std::cout << "Welcome!!!" << std::endl;

	while (name == "")
	{
		std::cout << "Enter: [1] for HEAP Zombie, [2] for STACK Zombie or [EXIT]" << std::endl;
		std::getline(std::cin, mem);
		if (mem == "EXIT")
		{
			return (EXIT_SUCCESS);
		}
		if (atoi(mem.c_str()) != 1 && atoi(mem.c_str()) != 2)
		{
			std::cout << "You only have 3 options !!!" << std::endl;
			continue ;	
		}
		std::cout << "Enter the zombie's name:" << std::endl;
		std::getline(std::cin, name);
		if (atoi(mem.c_str()) == 1)
		{
			zombie = newZombie(name);
			zombie->announce();
			delete zombie;
		}
		if (atoi(mem.c_str()) == 2)
			randomChump(name);
		name = "";

	}
	return (EXIT_SUCCESS);
}
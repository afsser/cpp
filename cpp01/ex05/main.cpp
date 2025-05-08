#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl		harl;

	if (argc != 2)
	{
		std::cerr << RED << "Usage: ./harlFilter <level>" << RST << std::endl;
		return (EXIT_FAILURE);
	}
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}
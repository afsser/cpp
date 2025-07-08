#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Usage example: " << argv[0] << " <filename>" << RST << std::endl;
		return (1);
	}
	BitcoinExchange	btc;
	btc.dbLoad("data.csv");
	btc.fileLoad(argv[1]);
	return (0);
}
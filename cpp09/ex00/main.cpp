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
	if (!btc.dbLoad("data.csv"))
		return (1);
	if (!btc.fileLoad(argv[1]))
		return (1);
	btc.printInputData();
	return (0);
}
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
	std::map<int, float> _inputData;
	std::map<int, float> _processedData;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void	dbLoad(const std::string &input);
	void	fileLoad(const std::string &input);
};
#endif
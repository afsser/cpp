#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {
	// Constructor implementation
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		// Assignment operator implementation
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	// Destructor implementation
}

static std::string removeDashes(std::string &date) {
	std::string result;
	result = date;
	result.erase(
		std::remove(result.begin(), result.end(), '-'),
		result.end()
	);
	return (result);
}

void BitcoinExchange::dbLoad(const std::string &input) {
	if (input.empty()) {
		std::cerr << "Error: Input is empty." << std::endl;
		return ;
	}
	std::ifstream file(input.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << input << std::endl;
		return ;
	}
	std::string line;
	std::string date;
	std::string valueStr;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#') {
			continue ;
		}
		date = line.substr(0, line.find(','));
		valueStr = line.substr(line.find(',') + 1);
		this->_inputData.insert(std::make_pair(
			std::atoi(removeDashes(date).c_str()),
			std::strtod(valueStr.c_str(), NULL)
		));
	}
}
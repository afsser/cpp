#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <list>
#include <map>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<int, float> BitcoinExchange::getInputData() const {
	return this->_inputData;
}

std::map<int, float> BitcoinExchange::getBaseData() const {
	return this->_baseData;
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

static bool isValidNumber(const std::string &str, double &outValue) {
	char *endptr;
	outValue = std::strtod(str.c_str(), &endptr);
	while (*endptr == ' ' || *endptr == '\t') ++endptr;
	return (*endptr == '\0');
}

// Função utilitária para remover espaços do início e fim de uma string
static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::dbLoad(const std::string &fileName) {
	std::ifstream file(fileName.c_str());
	if (!file.is_open()) {
		std::cerr << RED "Error: Could not open file " RST << fileName << std::endl;
		return false;
	}
	std::string line;
	std::string date;
	std::string valueStr;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#') {
			continue ;
		}
		date = line.substr(0, line.find(','));
		if (trim(date) == "date") {
			continue ;
		}
		valueStr = line.substr(line.find(',') + 1);
		double value;
		if (!isValidNumber(valueStr, value)) {
			std::cerr << RED "Error: Invalid number format in base data: '" << valueStr << "' for date " << date << RST << std::endl;
			continue ;
		}
		this->_baseData.insert(std::make_pair(
			std::atoi(removeDashes(date).c_str()),
			value
		));
	}
	if (this->_baseData.empty()) {
		std::cerr << RED "Error: No valid data found in file " RST << fileName << std::endl;
		return false;
	}
	return true;
}

// Atualiza o método fileLoad para usar std::list
bool BitcoinExchange::fileLoad(const std::string &fileName) {
	if (fileName != "input.txt") {
		std::cerr << RED "Error: Invalid file name. Expected 'input.txt'." RST << std::endl;
		return false;
	}
	std::ifstream file(fileName.c_str());
	if (!file.is_open()) {
		std::cerr << RED "Error: Could not open file " RST << std::endl;
		return false;
	}
	std::string line;
	std::string date;
	std::string valueStr;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#') {
			continue ;
		}
		date = line.substr(0, line.find('|'));
		if (trim(date) == "date") {
			continue ;
		}
		valueStr = line.substr(line.find('|') + 1);
		double value;
		if (!isValidNumber(valueStr, value)) {
			std::cerr << RED "Error: Invalid number format in input: '" << valueStr << "' for date " << date << RST << std::endl;
			continue ;
		}
		_inputData[std::atoi(removeDashes(date).c_str())] = value;
	}
	if (_inputData.empty()) {
		std::cerr << RED "Error: No valid data found in file " RST << fileName << std::endl;
		return false;
	}
	return true;
}

std::string editedDate(int date) {
    std::ostringstream oss;
    oss << date;
    std::string strDate = oss.str();
    if (strDate.length() == 8) {
        return strDate.substr(0, 4) + "-" + strDate.substr(4, 2) + "-" + strDate.substr(6, 2);
    }
    return "error";
}

// Atualiza printInputData para iterar sobre o vector
void BitcoinExchange::printInputData() const {
	for (std::map<int, float>::const_iterator it = _inputData.begin(); it != _inputData.end(); ++it) {
		int date = it->first;
		float value = it->second;
		if (date < 20090102 || date > 20220329) {
			std::cerr << RED "Error: Date out of range " YEL << editedDate(date) << RST << std::endl;
			continue ;
		}
		if (value < 0) {
			std::cerr << RED "Error: Date " YEL << editedDate(date) << RED " have negative value " YEL << value << RST << std::endl;
			continue ;
		}
		if (value > 1000) {
			std::cerr << RED "Error: Value too large (higher than 1000) " YEL << value << RED " for date " RST << editedDate(date) << std::endl;
			continue ;
		}
		std::cout << ORG "Date: " YEL << editedDate(date) << ORG ", Value: " YEL << value << ORG " => " BLU << value * getBaseData().at(date) << RST << std::endl;
	}
}
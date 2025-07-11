/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:20:39 by fcaldas-          #+#    #+#             */
/*   Updated: 2025/07/11 19:20:40 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

static bool isLeapYear(int year) {
	int firstLeapYear = 2008;
	return (year >= firstLeapYear && (year - firstLeapYear) % 4 == 0);
}

static int getDaysInMonth(int year, int month) {
	if (month < 1 || month > 12)
		return 0;
	int monthDays[] = { 31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (monthDays[month - 1]);
}

static bool isValidDate(const std::string &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(date[i])) {
			return false;
		}
	}
	int year = std::atoi((date.substr(0, 4)).c_str());
	int month = std::atoi((date.substr(5, 2)).c_str());
	int day = std::atoi((date.substr(8, 2)).c_str());
	if (year < 1 || year > 2022) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (day < 1 || day > getDaysInMonth(year, month)) {
		return false;
	}
	return true;
}

static bool isValidNumber(const std::string &str, double &outValue) {
	char *endptr;
	if (str.empty()) {
		return false;
	}
	outValue = std::strtod(str.c_str(), &endptr);
	while (*endptr == ' ' || *endptr == '\t') ++endptr;
	return (*endptr == '\0');
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
		date = trim(date);
		if (date == "date") {
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

void BitcoinExchange::fileProcess(const std::string &fileName) {
	if (fileName.substr(fileName.find_last_of(".") + 1) != "txt") {
		std::cerr << RED "Error: Invalid file name. Expected a .txt file." RST << std::endl;
		return ;
	}
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		std::cerr << RED "Error: Could not open file " RST << std::endl;
	std::string line;
	std::string date;
	std::string valueStr;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#') {
			continue ;
		}
		date = line.substr(0, line.find('|'));
		date = trim(date);
		if (date == "date") {
			continue ;
		}
		valueStr = line.substr(line.find('|') + 1);
		valueStr = trim(valueStr);
		double value;
		if (!isValidDate(date)) {
			std::cerr << RED "Error: Invalid date in input: '" YEL << date << RED "'." RST << std::endl;
			continue ;
		}
		if (!isValidNumber(valueStr, value)) {
			std::cerr << RED "Error: Invalid value format in input for date " YEL << date << RST << std::endl;
			continue ;
		}
		if (value < 0) {
			std::cerr << RED "Error: Negative value " YEL << value << RED " for date " YEL << date << RST << std::endl;
			continue ;
		}
		if (value > 1000) {
			std::cerr << RED "Error: Value too large (higher than 1000) " YEL << value << RED " for date " YEL << date << RST << std::endl;
			continue ;
		}
		int intDate = std::atoi(removeDashes(date).c_str());
		if (intDate < 20090102 || intDate > 20220329) {
			std::cerr << RED "Error: Date " YEL << date << RED " out of range" RST << std::endl;
			continue ;
		}
		while (this->_baseData.find(intDate) == this->_baseData.end()) {
			intDate--;
		}
		std::cout << ORG "Date: " YEL << date << ORG ", Value: " YEL << value << ORG " => " BLU
		          << value * this->_baseData[intDate] << RST << std::endl;
	}
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

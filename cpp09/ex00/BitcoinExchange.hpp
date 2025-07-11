/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:20:44 by fcaldas-          #+#    #+#             */
/*   Updated: 2025/07/11 19:20:45 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
	std::map<int, float> _inputData;
	std::map<int, float> _baseData;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	bool	dbLoad(const std::string &input);
	void	fileProcess(const std::string &input);
	std::map<int, float> getBaseData() const;
	std::map<int, float> getInputData() const;
	void	printInputData() const;
};
#endif
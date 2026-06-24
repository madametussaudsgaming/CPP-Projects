/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:37:18 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/24 21:56:29 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::fillValues(std::string lineData) {
	this->_date = lineData.substr(0, lineData.find(","));
	lineData.erase(0, lineData.find(","));
	this->_value = std::atof(lineData.c_str());
	std::cout<<this->_date<<std::endl;
	std::cout<<this->_value<<std::endl;
	this->_btcData.insert(std::make_pair(_date, _value));
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream allData("data.csv");
	if (!allData.is_open())
		throw (std::string) "Data.csv cannot be opened.";
	std::string lineData;
	getline(allData, lineData);
	//skip first line
	while (getline(allData, lineData))
		fillValues(lineData);
	allData.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->_value = other._value;
	this->_date = other._date;
	this->_btcData = other._btcData;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
	{
		this->_value = other._value;
		this->_date = other._date;
		this->_btcData.clear();
		this->_btcData = other._btcData;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
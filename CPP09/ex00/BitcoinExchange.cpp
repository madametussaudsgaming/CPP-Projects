/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:37:18 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/28 18:40:54 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::string detectCsvDelimiter(const std::string& header) {
	const std::string key = "date";
	size_t pos = header.find(key);
	if (pos == std::string::npos)
		return ",";
	pos += key.size();
	size_t wordStart = header.find_first_of(
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", pos);
	if (wordStart == std::string::npos)
		return ",";
	return header.substr(pos, wordStart - pos);
}

void BitcoinExchange::fillValues(std::string lineData) {
	size_t delimPos = lineData.find(_csvDelimiter);
	if (delimPos == std::string::npos)
		return;
	this->_date = lineData.substr(0, delimPos);
	std::string valueStr = lineData.substr(delimPos + _csvDelimiter.size());
	this->_value = std::atof(valueStr.c_str());
	this->_btcData.insert(std::make_pair(_date, _value));
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream allData("data.csv");
	if (!allData.is_open())
		throw (std::string) "data.csv cannot be opened.";
	std::string header;
	getline(allData, header);
	_csvDelimiter = detectCsvDelimiter(header);
	std::string lineData;
	while (getline(allData, lineData))
		fillValues(lineData);
	allData.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->_value = other._value;
	this->_date = other._date;
	this->_csvDelimiter = other._csvDelimiter;
	this->_btcData = other._btcData;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
	{
		this->_value = other._value;
		this->_date = other._date;
		this->_csvDelimiter = other._csvDelimiter;
		this->_btcData.clear();
		this->_btcData = other._btcData;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool isValidDate(const std::string& date) {
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < 10; i++) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	static const int daysInMonth[12] =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeap)
		maxDay = 29;
	if (day > maxDay)
		return false;
	return true;
}

// Parses a value string fully as a number (leading/trailing whitespace
// allowed). Returns false if the string is empty or contains anything
// that isn't part of a valid number, instead of silently truncating
// like atof() does (e.g. "1abc" or "abc" used to be accepted).
static bool parseValue(const std::string& valueStr, double& out) {
	if (valueStr.empty())
		return false;
	const char* cstr = valueStr.c_str();
	char* endptr = NULL;
	out = std::strtod(cstr, &endptr);
	if (endptr == cstr)
		return false;
	while (*endptr == ' ' || *endptr == '\t')
		endptr++;
	if (*endptr != '\0')
		return false;
	return true;
}

void BitcoinExchange::processInput(std::string filename) {
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
		throw (std::string) "could not open file.";

	std::string header;
	getline(inputFile, header);
	std::string delim = detectCsvDelimiter(header);
	size_t cs = delim.find_first_not_of(" \t");
	size_t ce = delim.find_last_not_of(" \t");
	std::string coreSep = (cs == std::string::npos) ? delim : delim.substr(cs, ce - cs + 1);

	// Default stream precision is only 6 significant digits, which makes
	// large results (e.g. high BTC value * a large exchange rate) print
	// in scientific notation and lose precision on the cents. Raising it
	// keeps plain decimal notation while still dropping trailing zeros
	// (we don't force std::fixed, so "7.1" still prints as "7.1", not "7.100000").
	std::cout << std::setprecision(10);

	std::string line;
	while (getline(inputFile, line)) {
		size_t sep = line.find(coreSep);
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		size_t dateEnd = date.find_last_not_of(" \t");
		if (dateEnd == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = date.substr(0, dateEnd + 1);
		std::string valueStr = line.substr(sep + coreSep.size());
		size_t start = valueStr.find_first_not_of(" \t");
		if (start == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		valueStr = valueStr.substr(start);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		double value;
		if (!parseValue(valueStr, value)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		std::map<std::string, double>::iterator it = _btcData.lower_bound(date);
		if (it == _btcData.end() || it->first != date) {
			if (it == _btcData.begin()) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			--it;
		}
		std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
	}
	inputFile.close();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:00:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/27 17:48:55 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
  if (this == &other)
    return (*this);
  return (*this);
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {  *this = other;	}

bool	ScalarConverter::isChar(const std::string &rep)
{
	if (rep.length() == 1 && std::isprint(rep[0]) && !std::isdigit(rep[0]))
		return true;
	if (rep.length() == 3 && rep[0] == '\'' && rep[2] == '\'' && std::isprint(rep[1]))
		return true;
	return false;
}

bool	ScalarConverter::isInt(const std::string &rep)
{
	if (rep.empty())
		return (false);
	const size_t start = (rep[0] == '-' || rep[0] == '+') ? 1 : 0;
	if (rep.find_first_of("+-", start) != std::string::npos)
		return (false);
	if (rep.find_first_not_of("0123456789", start) != std::string::npos)
		return (false);
	return (true);
}


bool	ScalarConverter::isFloat(const std::string &rep)
{
	// if (rep.empty() || rep.back() != 'f')
    //     return (false);
	// try
	// {
	// 	std::stof(rep);
	// }
	// catch (std::exception &e)
	// {
	// 	return (false);
	// }
	// return (true);
	const size_t start = (rep[0] == '-' || rep[0] == '+') ? 1 : 0;
	if (rep.find_first_of("+-", start) != std::string::npos)
		return (false);

	const size_t dot = rep.find('.');
	if (dot == std::string::npos)
		return (false);

	if (rep[rep.size() - 1] != 'f')
		return (false);

	const std::string decimalPart = rep.substr(start, dot - start);
	const std::string fractionalPart =
		rep.substr(dot + 1, rep.size() - (dot + 2));
	// +2 make way for 'f'

	if (decimalPart.find_first_not_of("0123456789") != std::string::npos ||
		fractionalPart.find_first_not_of("0123456789") != std::string::npos)
		return (false);

	return (!decimalPart.empty() && !fractionalPart.empty());
}

bool	ScalarConverter::isDouble(const std::string &rep)
{
	// if (rep.empty() || rep.back() == 'f' )
    //     return (false);
	// try
	// {
	// 	std::stod(rep);
	// }
	// catch (std::exception &e)
	// {
	// 	return (false);
	// }
	// return (true);
	//using more ternaries, if pos[0] aint - or +, then start at 0.
	const size_t start = (rep[0] == '-' || rep[0] == '+') ? 1 : 0;
	if (rep.find_first_of("+-", start) != std::string::npos)
		return (false);

	const size_t dot = rep.find('.');
	if (dot == std::string::npos)
		return (false);
	//split 'string into pre and post '.'
	const std::string decimalPart = rep.substr(start, dot - start);
	const std::string fractionalPart = rep.substr(dot + 1, rep.size() - (dot + 1));

	if (decimalPart.find_first_not_of("0123456789") != std::string::npos ||
		fractionalPart.find_first_not_of("0123456789") != std::string::npos)
		return (false);

	return (!decimalPart.empty() && !fractionalPart.empty());
}

bool ScalarConverter::isPseudoLiteral(const std::string &rep)
{
  if (rep == "-inff" || rep == "+inff" ||
      rep == "nanf" || rep == "-inf" ||
      rep == "+inf" || rep == "nan")
    return true;
  return false;
}

static void printChar(const char &c) {
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void changeChar(const std::string &rep)
{
	char c = (rep.length() == 1) ? rep[0] : rep[1];
	printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	float f = static_cast<float>(c);
	float fIntPart;
	std::cout << "float: ";
	if (std::modf(f, &fIntPart) == 0.0f)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << f << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);

	double d = static_cast<double>(c);
	double dIntPart;
	std::cout << "double: ";
	if (std::modf(d, &dIntPart) == 0.0)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

static void changeNumbers(const std::string &rep)
{
	long double num = std::strtold(rep.c_str(), NULL);

	if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(num));

	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		float f = std::strtof(rep.c_str(), NULL);
		float fIntPart;
		std::cout << "float: ";
		if (std::modf(f, &fIntPart) == 0.0f)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << f << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}

	if (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
	{
		double d = std::strtod(rep.c_str(), NULL);
		double dIntPart;
		std::cout << "double: ";
		if (std::modf(d, &dIntPart) == 0.0)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << d << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}

// if (rep == "-inff" || rep == "+inff" ||
//       rep == "nanf" || rep == "-inf" ||
//       rep == "+inf" || rep == "nan")

static void changePseudoLiteral(const std::string &rep)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (rep.find("nan") != std::string::npos)
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (rep.find("inf") != std::string::npos)
	{
		std::cout << "float: " << rep[0] << "inff" << std::endl;
		std::cout << "double: " << rep[0] << "inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &representation)
{
	if (isChar(representation))
		changeChar(representation);
	else if (isInt(representation))
		changeNumbers(representation);
	else if (isFloat(representation))
		changeNumbers(representation);
	else if (isDouble(representation))
		changeNumbers(representation);
	else if (isPseudoLiteral(representation))
		changePseudoLiteral(representation);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

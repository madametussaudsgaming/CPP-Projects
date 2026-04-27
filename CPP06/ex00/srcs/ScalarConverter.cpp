/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:00:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/27 17:23:31 by rpadasia         ###   ########.fr       */
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
	if (rep.empty() || rep.length() != 1 || !std::isprint(rep[0]) || std::isdigit(rep[0]))
		return false;
	return (true);
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
  if (std::isprint(c)) {
    std::cout << "Char Representation: "
              << "'" << c << "'" << std::endl;
  } else
    std::cout << "Char Representation: NON-DISPLAYABLE"<< std::endl;
}

static void changeChar(const std::string &rep)
{
	printChar(rep[0]);
	std::cout<<"Int Representation: "<< static_cast<int>(rep[0])<<std::endl;
	std::cout<<"Float Representation: "<< static_cast<float>(rep[0])<<"f"<<std::endl;
	std::cout<<"Double Representation: "<< static_cast<double>(rep[0])<<std::endl;
}

static void changeNumbers(const std::string &rep)
{
	long double num = std::strtold(rep.c_str(), NULL);

	if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
		std::cout<<"Char Representation: OVERFLOWS"<<std::endl;
	else
		printChar(static_cast<char>(num));
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout<<"Int Representation: OVERFLOWS"<<std::endl;
	else
		std::cout<<"Int Representation: "<<std::atoi(rep.c_str())<<std::endl;
	if (num < std::numeric_limits<float>::min() || num > std::numeric_limits<float>::max())
		std::cout<<"Float Representation: OVERFLOWS"<<std::endl;
	else
		std::cout<<"Float Representation: "<<std::strtof(rep.c_str(), NULL)<<"f"<<std::endl;

	if (num < std::numeric_limits<double>::min() || num > std::numeric_limits<double>::max())
		std::cout<<"Double Representation: OVERFLOWS"<<std::endl;
	else
		std::cout<<"Double Representation: "<<std::strtod(rep.c_str(), NULL)<<std::endl;
}

// if (rep == "-inff" || rep == "+inff" ||
//       rep == "nanf" || rep == "-inf" ||
//       rep == "+inf" || rep == "nan")

static void changePseudoLiteral(const std::string &rep)
{
	std::cout<<"Char Representation: NONE"<<std::endl;
	std::cout<<"Int Representation: NONE"<<std::endl;
	if (rep.find("nan") != std::string::npos)
	{
		std::cout << "Float Representation: nanf"<< std::endl;
		std::cout << "Double Representation: nan" << std::endl;
	}
	else if (rep.find("inf") != std::string::npos)
	{
		std::cout << "Float Representation: "<<rep[0]<<"inff" << std::endl;
		std::cout << "Double Representation: "<<rep[0]<<"inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &representation)
{
	if (isChar(representation))
	{
		std::cout<<"IS CHAR"<<std::endl;
  		changeChar(representation);
	}
	else if (isInt(representation))
	{
		std::cout<<"IS INT"<<std::endl;
		changeNumbers(representation);
	}
	else if (isFloat(representation))
	{
		std::cout<<"IS FLOAT"<<std::endl;
		changeNumbers(representation);
	}
	else if (isDouble(representation))
	{
		std::cout<<"IS DOUBLE"<<std::endl;
		changeNumbers(representation);
	}
	else if (isPseudoLiteral(representation))
	{
		changePseudoLiteral(representation);
	}
	else
		std::cout<<"UNKNOWN"<<std::endl;

	// std::cout<<isChar(representation)<<std::endl;
	// std::cout<<isInt(representation)<<std::endl;
	// std::cout<<isFloat(representation)<<std::endl;
	// std::cout<<isDouble(representation)<<std::endl;
	// std::cout<<isPseudoLiteral(representation)<<std::endl;
}

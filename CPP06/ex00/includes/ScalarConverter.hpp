/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:00:21 by rpadasia          #+#    #+#             */
/*   Updated: 2026/05/02 11:42:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
public:
	static void convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	virtual ~ScalarConverter() = 0;

	static bool	isChar(const std::string &rep);
	static bool	isInt(const std::string &rep);
	static bool	isFloat(const std::string &rep);
	static bool	isDouble(const std::string &rep);
	static bool isPseudoLiteral(const std::string &rep);
};

//get used to find(),size(), empty(),strtold(), strtof()

#endif
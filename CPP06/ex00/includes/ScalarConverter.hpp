/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:00:21 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/25 17:18:10 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
public:
	static void convert(const std::string& literal);
	
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	virtual ~ScalarConverter() = 0;
};

//get used to find(),size(), empty(),strtold(), strtof()
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:00:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/25 17:18:10 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void ScalarConverter::convert(const std::string &representation) {
//   if (isChar(representation)) {
//     convertFromChar(representation);
//     // std::cout << "Is a char." << std::endl;
//   } else if (isInteger(representation)) {
//     convertToNumber(representation, std::strtold(representation.c_str(), NULL));
//     // std::cout << "Is a integer." << std::endl;
//   } else if (isFloat(representation)) {
//     convertToNumber(representation, std::strtold(representation.c_str(), NULL));
//     // std::cout << "Is a float." << std::endl;
//   } else if (isDouble(representation)) {
//     convertToNumber(representation, std::strtold(representation.c_str(), NULL));
//     // std::cout << "Is a double." << std::endl;
//   } else if (isInfinite(representation)) {
//     convertFromInfinite(representation);
//   } else
//     std::cout << "Unknown type" << std::endl;
// }
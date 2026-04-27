/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:00:30 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/27 15:53:00 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 3)
    return (1);
  std::string abc = argv[1];
  ScalarConverter::convert(abc);
  std::cout<<std::endl<<abc<<std::endl;
}
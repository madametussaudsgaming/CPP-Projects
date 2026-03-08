/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:57 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/08 15:44:50 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	// std::cout<<"a done"<<std::endl;
	Fixed b(a);
	// std::cout<<"b done"<<std::endl;
	Fixed c;

	c = b;
	// std::cout<<"c done"<<std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:57 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/30 18:22:18 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>


int	main(void)
{
	const Point a(0.0, 0.0);
	const Point b(10.0, 30.0);
	const Point c(20.0, 0.0);
	const Point point(30.0, 15.0);
	std::cout<<(bsp(a, b, c, point))<<std::endl;
}

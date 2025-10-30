/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:43:19 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/30 17:46:15 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculate_area(Point const a, Point const b, Point const c)
{
	Fixed area;
	Fixed(0.5f) * (a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y()));
	if (area < 0)
		area = area * -1;
	return (area);
}

bool bsp ( Point const a, Point const b, Point const c, Point const point)
{
	Fixed total_area;
	Fixed PAB;
	Fixed PAC;
	Fixed PBC;

	total_area = calculate_area(a, b, c);
	PAB = calculate_area(a, b, point);
	PAC = calculate_area(a, c, point);
	PBC = calculate_area(b, c, point);
	if (PAB == 0 || PAC == 0 || PBC == 0)
		return (false);
	return (total_area == PAB + PAC + PBC);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:45:33 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/30 17:07:17 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x1, const float y1) : x(x1), y(y1) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	std::cerr<<"Cannot assign to const Point"<<std::endl;
	return (*this);
}

Point::~Point() {}

const Fixed Point::get_x() const { return (x); }

const Fixed Point::get_y() const { return (y); }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:45:39 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/30 17:07:11 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
	const Fixed x;
	const Fixed y;

	public:
	Point();
	Point(const float x1, const float y1);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	const Fixed get_x() const;
	const Fixed get_y() const;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:48:09 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/08 16:27:09 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T& x, T& y) {
    T temp = x;
	x = y;
	y = temp;
}

//says RETURN not RETURN A COPY
template <typename T1> T1 min(const T1& val1, const T1& val2) {
	if (val1 == val2)
		return (val2);
	return (val1 < val2) ? val1 : val2;
}

template <typename T2> T2 max(const T2& val1, const T2& val2) {
	if (val1 == val2)
		return (val2);
	return (val1 > val2) ? val1 : val2;
}

#endif
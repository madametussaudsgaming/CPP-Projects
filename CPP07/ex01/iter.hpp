/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:05:46 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/06 15:34:14 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

// template <typename T1, int INIT, typename T3> void iter(T1 addr, const T2 len, T3 iterate) {

// }

#include <iostream>
#include <functional>

template <typename address, typename function> void iter(address *addr, long arrayLength, void(*func)(function)) {
	for (int i = 0; i < arrayLength; i++)
		func(addr[i]);
}

#endif
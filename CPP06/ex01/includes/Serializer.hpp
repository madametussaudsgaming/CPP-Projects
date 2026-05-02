/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:19:04 by rpadasia          #+#    #+#             */
/*   Updated: 2026/05/02 11:42:48 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdint.h>

struct Data {
	uintptr_t data;
};

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static Data* deserialize(uintptr_t raw);
		//It takes an unsigned integer parameter and converts it to a pointer to Data.

	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		virtual ~Serializer() = 0;
};

#endif
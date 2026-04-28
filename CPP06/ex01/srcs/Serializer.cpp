/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:28:05 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/28 16:39:08 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

//It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t ret = reinterpret_cast <uintptr_t> (ptr);
	return (ret);
}
//It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ret = reinterpret_cast <Data*> (raw);
	return (ret);
}

Serializer::Serializer() {}

Serializer& Serializer::operator=(const Serializer &other)
{
  if (this == &other)
  	return (*this);
  return (*this);
}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other) {  *this = other;	}
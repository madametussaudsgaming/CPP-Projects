/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:28:33 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 02:32:54 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string &Weapon::getType() const
{
	return (type);
}

void Weapon::setType(const std::string &newtype)
{
	type = newtype;
}

Weapon::Weapon() {};

Weapon::Weapon(const std::string &tbtype) :	type(tbtype) {}

Weapon::~Weapon() {};
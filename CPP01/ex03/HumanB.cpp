/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:40:59 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 16:08:29 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (!hB_weapon)
		std::cout<<name<<" has no weapon!"<<std::endl;
	else
		std::cout<<name<<" attacks with "<<hB_weapon->getType()<<std::endl;
}

void	HumanB::setWeapon(Weapon &tbset)
{
	hB_weapon = &tbset;
}

HumanB::HumanB(std::string tbname, Weapon *type)
{
	hB_weapon = type;
	name = tbname;
}

HumanB::HumanB(std::string tbname) : hB_weapon(NULL), name(tbname) {}

HumanB::~HumanB() {}
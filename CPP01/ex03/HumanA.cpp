/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:58:57 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 02:21:30 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout<<name<<" attacks with "<<hA_weapon.getType()<<std::endl;
}

HumanA::HumanA(std::string tbname, Weapon& type) : hA_weapon(type), name(tbname) {}

HumanA::~HumanA() {}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:20:14 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/24 23:11:18 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout<<"Default constructor called"<<std::endl;
	name = "Defualt";
}

ClapTrap::ClapTrap(std::string tbname)
{
	std::cout<<"Constructor called"<<std::endl;
	name = tbname;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy Assignment Operator called" << std::endl;

    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& variables)
	: name(variables.name),
      hit_points(variables.hit_points),
      energy_points(variables.energy_points),
      attack_damage(variables.attack_damage)
{
	std::cout<<"Copy Constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"Destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout<<"Claptrap "<<name<<" attacks "<<target<<", causing "<<attack_damage<<" points of dmaage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points -= amount;
	std::cout<<"Claptrap "<<name<<" took "<<amount<<" points of damage!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hit_points += amount;
	std::cout<<"Claptrap "<<name<<" was repaired for "<<amount<<" HP!"<<std::endl;
}

void ClapTrap::displayStats(void)
{
	std::cout<<hit_points<<std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:20:14 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/25 13:51:01 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout<<"ClapTrap Default constructor called"<<std::endl;
	name = "Defualt";
}

ClapTrap::ClapTrap(std::string tbname)
{
	std::cout<<"ClapTrap Constructor called"<<std::endl;
	name = tbname;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;

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
	std::cout<<"ClapTrap Copy Constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap Destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_points > 0 &&this->hit_points > 0)
	{
		std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<attack_damage<<" points of dmaage!"<<std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout<<"ClapTrap "<<this->name<<" is out of energy!"<<std::endl;
	else
		std::cout<<"ClapTrap "<<this->name<<" is out of HP!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > amount)
		this->hit_points -= amount;
	else if (this->hit_points > 0)
		this->hit_points = 0;
	else
	{
		std::cout<<"This Claptrap is already dead!"<<std::endl;
		return ;
	}
	std::cout<<"Claptrap "<<name<<" took "<<amount<<" points of damage!"<<std::endl;
	std::cout<<"Claptrap has "<<this->hit_points<<" HP left!"<<std::endl;
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
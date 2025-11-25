/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:14:20 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/25 20:11:50 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->name = "Default";
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
	this->guarding_gate = false;
	std::cout<<"ScavTrap Default Constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &og): ClapTrap(og)
{
	this->guarding_gate = og.guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap()
{
	this->name = name;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
	this->guarding_gate = false;
	std::cout<<"ScavTrap Constructor called"<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &og)
{
	std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
	if (this != &og)
	{
		ClapTrap::operator=(og);
		this->guarding_gate = og.guarding_gate;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap Deconstructor called"<<std::endl;
}

// PUBLICA

void ScavTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 &&this->hit_points > 0)
	{
		std::cout<<"ScavTrap "<<name<<" attacks "<<target<<", causing "<<attack_damage<<" points of dmaage!"<<std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout<<"ScavTrap "<<name<<" is out of energy!"<<std::endl;
	else
		std::cout<<"ScavTrap "<<name<<" is out of HP!"<<std::endl;
}

void ScavTrap::guardGate()
{
	if (this->guarding_gate == false)
	{
		std::cout<<"ScavTrap "<<name<<" guards a gate!"<<std::endl;
		guarding_gate = true;
	}
	else
		std::cout<<"ScavTrap "<<name<<" is already guarding a gate!"<<std::endl;
}

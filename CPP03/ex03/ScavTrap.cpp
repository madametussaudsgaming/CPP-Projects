/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:14:20 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/25 21:23:29 by rpadasia         ###   ########.fr       */
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > amount)
		this->hit_points -= amount;
	else if (this->hit_points > 0)
		this->hit_points = 0;
	else
	{
		std::cout<<"This ScavTrap is already dead!"<<std::endl;
		return ;
	}
	std::cout<<"ScavTrap "<<name<<" took "<<amount<<" points of damage!"<<std::endl;
	std::cout<<"ScavTrap has "<<this->hit_points<<" HP left!"<<std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->hit_points += amount;
		std::cout<<"ScavTrap "<<this->name<<" repaired itself for "<<amount<<" HP!"<<std::endl;
		std::cout<<"ScavTrap now has "<<this->hit_points<<" HP!"<<std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout<<"ScavTrap is too exhausted to repair itself."<<std::endl;
	else
		std::cout<<"Dead ScavTraps can't repair themselves."<<std::endl;
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

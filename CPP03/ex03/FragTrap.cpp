/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:03:56 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/25 21:29:31 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->name = "Default";
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 100;
	std::cout<<"FragTrap Default Constructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &og): ClapTrap(og)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap()
{
	this->name = name;
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 100;
	std::cout<<"FragTrap Constructor called"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &og)
{
	std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
	if (this != &og)
	{
		ClapTrap::operator=(og);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap Deconstructor called"<<std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 &&this->hit_points > 0)
	{
		std::cout<<"FragTrap "<<name<<" attacks "<<target<<", causing "<<attack_damage<<" points of dmaage!"<<std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout<<"FragTrap "<<name<<" is out of energy!"<<std::endl;
	else
		std::cout<<"FragTrap "<<name<<" is out of HP!"<<std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > amount)
		this->hit_points -= amount;
	else if (this->hit_points > 0)
		this->hit_points = 0;
	else
	{
		std::cout<<"This FragTrap is already dead!"<<std::endl;
		return ;
	}
	std::cout<<"FragTrap "<<name<<" took "<<amount<<" points of damage!"<<std::endl;
	std::cout<<"FragTrap has "<<this->hit_points<<" HP left!"<<std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->hit_points += amount;
		std::cout<<"FragTrap "<<this->name<<" repaired itself for "<<amount<<" HP!"<<std::endl;
		std::cout<<"FragTrap now has "<<this->hit_points<<" HP!"<<std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout<<"FragTrap is too exhausted to repair itself."<<std::endl;
	else
		std::cout<<"Dead FragTraps can't repair themselves."<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout<<"I have 'Highed your Five'."<<std::endl;
}
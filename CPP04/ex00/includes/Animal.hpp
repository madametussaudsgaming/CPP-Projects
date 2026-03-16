/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:10:40 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:01:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string.h>

class Animal
{
	protected:
		std::string type;
	public:
	// explicit implies constructor cannot be implicitly called (through inheritance chain)
		explicit Animal();
		Animal(std::string type);
		Animal(const Animal& ori);
		Animal& operator=(const Animal& ori);
		virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;
};

#endif
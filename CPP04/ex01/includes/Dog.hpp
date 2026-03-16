/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:14:51 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 18:43:51 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	private:
		Brain *dogBrain;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &ori);
		Dog &operator=(const Dog &ori);
		virtual ~Dog();
	void makeSound() const;
};

#endif
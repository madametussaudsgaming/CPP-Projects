/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:14:49 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:14:51 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &ori);
		Cat &operator=(const Cat &ori);
		virtual ~Cat();
		//see what happens if shit aint virtual
	void makeSound() const;
};

#endif
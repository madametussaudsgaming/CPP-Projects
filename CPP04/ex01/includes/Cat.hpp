/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:14:49 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 18:43:46 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	private:
		Brain *catBrain;
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
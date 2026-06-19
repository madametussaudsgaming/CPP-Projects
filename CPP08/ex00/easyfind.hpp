/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:09:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/19 10:18:47 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>



template <typename T> typename T::iterator easyfind(T& c, int i) {
	class notFound : public std::exception {
	public:
  		const char *what() const throw() { return "Value not found in this container!"; }
	};
	typename T::iterator iter = std::find(c.begin(), c.end(), i);
	if (iter == c.end())
		throw notFound();
	return iter;
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:09:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/18 17:20:40 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class notFound : public std::exception {
public:
  const char *what() const throw() { return "Value not found in this container!"; }
};

template <typename T> typename T::iterator easyfind(T& c, int i) {
	typename T::iterator iter = std::find(c.begin(), c.end(), i);
	if (iter == c.end())
		throw notFound();
	return iter;
}

#endif
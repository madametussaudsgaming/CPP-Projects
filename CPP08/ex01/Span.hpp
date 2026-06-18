/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:09:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/16 22:48:09 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int size_;
		std::vector<int> intStore;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		template <typename InputIterator>
		void	addRange(InputIterator first, InputIterator last) {
			while (first != last) {
				addNumber(*first);
				++first;
			}
		}
		int		shortestSpan();
		int		longestSpan();

		class noSpace : public std::exception {
			const char *what() const throw();
		};
		class noSpanFound : public std::exception {
			const char *what() const throw();
		};


};

#endif
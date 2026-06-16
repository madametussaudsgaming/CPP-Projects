/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:42:40 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/16 23:00:28 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
  Span A(10);
  try {
    A.addNumber(10);
    std::cout<<A.longestSpan()<<std::endl;
    std::cout<<A.shortestSpan()<<std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
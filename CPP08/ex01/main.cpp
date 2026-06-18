/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:42:40 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/17 15:46:46 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
  // Subject example — must print 2 then 14
  Span sp(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  // Exception: too full
  try {
    sp.addNumber(42);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // Exception: too few elements
  try {
    Span empty(1);
    empty.addNumber(5);
    empty.shortestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // 10,000 numbers via addRange
  std::srand(42);
  std::vector<int> big;
  for (int i = 0; i < 10000; i++)
    big.push_back(std::rand());
  Span large(10000);
  large.addRange(big.begin(), big.end());
  std::cout << "Shortest (10k): " << large.shortestSpan() << std::endl;
  std::cout << "Longest  (10k): " << large.longestSpan() << std::endl;

  return 0;
}
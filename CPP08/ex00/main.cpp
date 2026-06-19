/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:42:40 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/19 10:32:08 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  std::vector<int> vec;
  for (int i = 0; i < 10; i++)
    vec.push_back(std::rand() % 10);

  std::cout << "Vector: ";
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  try {
    int target = std::rand() % 12;
    std::cout << "Searching for " << target << " in vector: ";
    std::vector<int>::iterator it = easyfind(vec, target);
    std::cout << "Found at index " << std::distance(vec.begin(), it) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(4);
  lst.push_back(5);

  try {
    std::cout << "Searching for 3 in list: ";
    easyfind(lst, 3);
    std::cout << "Found!" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "Searching for 99 in list: ";
    easyfind(lst, 99);
    std::cout << "Found!" << std::endl; 
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
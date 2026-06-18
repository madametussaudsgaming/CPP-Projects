/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:42:40 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/18 16:45:00 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main() {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it  = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  // Verify same output with std::list
  std::cout << "--- list ---" << std::endl;
  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);
  for (std::list<int>::iterator li = lst.begin(); li != lst.end(); ++li)
    std::cout << *li << std::endl;

  // Confirm MutantStack is copy-constructible into std::stack
  std::stack<int> s(mstack);
  std::cout << "std::stack size: " << s.size() << std::endl;

  return 0;
}

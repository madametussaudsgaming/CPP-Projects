/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:00:30 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/25 14:05:57 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

class Base {
  public:
    virtual void print() {}
};

class Derived: public Base {};

int main() {
  Base* b = new Derived();
  Derived* d = dynamic_cast <Derived*> (b);

  if (d != NULL) {
    cout << "dynamic_cast done" << endl;
  } else {
    cout << "dynamic_cast not done" << endl;
  }

  return 0;
}
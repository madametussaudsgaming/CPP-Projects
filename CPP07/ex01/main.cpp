/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:05:54 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/06 15:47:24 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printChar(char c) {
	std::cout << c << std::endl;
}

void printInt(int c) {
	std::cout << std::endl << c;
}

int main() {
	std::string arr = "READ THIS!";
	long len = arr.size();
	iter<char>(&arr[0], len, printChar);
	int arr2[] = {1, 2, 3, 4, 5};
	long len1 = sizeof(arr2) / sizeof(arr2[0]);
	iter<int>(&arr2[0], len1, printInt);
	std::cout<<std::endl;
}

//my printChar is a plain (non-template) function — it has a fixed signature void(char).
//When the compiler sees it passed to iter, it already knows the exact type, so it
//deduces function = char from the argument automatically.
//Template type deduction works by matching the function argument's type against the
//template parameter. Since printChar is concretely typed as void(*)(char),
//the compiler pattern-matches that against void(*func)(function) and concludes function
//must be char — no ambiguity, nothing to specify manually.
//If printChar were itself a template (e.g. template<typename T> void printChar(T c)),
//you'd need to write printChar<char> to disambiguate, because a template function name alone
//has no single resolved type.
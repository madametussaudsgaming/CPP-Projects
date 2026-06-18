/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:15:34 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/18 17:33:06 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size_(0) {
	std::cout << "Default Constructor called!" << std::endl;
}

Span::Span(unsigned int n) : size_(n) {
	std::cout << "Constructor called!" << std::endl;
}

Span::Span(const Span& other) : size_(0) {
	std::cout << "Copy Constructor called!" << std::endl;
	this->size_ = other.size_;
	this->intStore = other.intStore;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Copy ASssignment operator called!" << std::endl;
	if (this == &other)
		return *this;
	this->size_ = other.size_;
	this->intStore = other.intStore;
	return *this;
}

Span::~Span() {
	std::cout << "Destructor called!" << std::endl;
}

void Span::addNumber(int number) {
  if (this->intStore.size() + 1 > this->size_)
    throw noSpace();
  this->intStore.push_back(number);
}

void Span::addRandomNumbers(unsigned int quantity) {
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  while (quantity > 0) {
    int randomNum = std::rand() - RAND_MAX / 2;
    this->addNumber(randomNum);
    std::cout << "Random number added: " << randomNum << std::endl;
    quantity--;
  }
}

int		Span::shortestSpan() {
	if (this->intStore.size() < 2)
		throw noSpanFound();
	std::vector<int> sorted(this->intStore);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (std::vector<int>::size_type i = 1; i + 1 < sorted.size(); ++i) {
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int		Span::longestSpan() {
	if (this->intStore.size() < 2)
		throw noSpanFound();
	std::vector<int>::iterator it_max = std::max_element(this->intStore.begin(), this->intStore.end());
	std::vector<int>::iterator it_min = std::min_element(this->intStore.begin(), this->intStore.end());
	return (abs(*it_max - *it_min));
}

const char *Span::noSpace::what() const throw() {
  return "NO SPACE LEFT IN CONTAINER";
}

const char *Span::noSpanFound ::what() const throw() {
  return "NO SPAN FOUND";
}
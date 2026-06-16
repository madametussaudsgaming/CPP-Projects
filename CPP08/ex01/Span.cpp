/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:15:34 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/16 23:02:01 by rpadasia         ###   ########.fr       */
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



void Span::addNumber(unsigned int n) {
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  while (n > 0)
  {
    int randomNum = std::rand() % 150;
	if (this->intStore.size() + 1 > this->size_)
		throw (noSpace());
    this->intStore.push_back(randomNum);
    std::cout << "Number added: " << randomNum << std::endl;
    n--;
  }
}

int		Span::shortestSpan() {
	if (this->intStore.size() < 2)
		throw noSpanFound();
	std::sort(this->intStore.begin(), this->intStore.end());
	std::vector<int>::iterator it = this->intStore.begin();
	int minSpan = abs(*it - *(it + 1));
	//iterate through find smallest difference

	while (it != this->intStore.end())
	{
		if (abs(*it - *(it + 1)) < minSpan)
			minSpan = (abs(*it - *(it + 1)));
		it++;
	}
	return (minSpan);
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
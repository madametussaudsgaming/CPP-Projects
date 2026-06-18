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

Span::Span() : size_(0) {}

Span::Span(unsigned int n) : size_(n) {}

Span::Span(const Span& other) : size_(other.size_), intStore(other.intStore) {}

Span& Span::operator=(const Span& other) {
	if (this == &other)
		return *this;
	this->size_ = other.size_;
	this->intStore = other.intStore;
	return *this;
}

Span::~Span() {}



void Span::addNumber(int n) {
  if (this->intStore.size() >= this->size_)
    throw noSpace();
  this->intStore.push_back(n);
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
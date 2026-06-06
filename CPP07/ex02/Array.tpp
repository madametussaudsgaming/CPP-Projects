/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:06:50 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/06 16:53:53 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T> Array<T>::Array() : siz() {
	this->array = new T[0];
	this->siz = 0;
};

template <class T> Array<T>::Array(unsigned int n) : siz(n) {
	this->array = new T[n];
}

template <class T> Array<T>::Array(const Array &other) {
	this->array = new T[other.size()];
 	for (unsigned int i = 0; i < other.size(); i++)
		this->array[i] = other.array[i];
	this->siz = other.siz;
}

template <class T> Array<T> &Array<T>::operator=(const Array &other) {
	if (this == &other)
		return (*this);
	delete[] this->array;
	this->array = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); i++)
		this->array[i] = other.array[i];
	this->siz = other.siz;
	return *this;
}

template <class T> Array<T>::~Array() {
	delete[] this->array;
}

template <class T> unsigned int Array<T>::size() const {
	return siz;
};

template <class T> T &Array<T>::operator[] (unsigned int i) {
	if (i >= this->size())
		throw OutOfRange();
	return this->array[i];
};

template <class T> const char *Array<T>::OutOfRange::what() const throw() {
  return "Index Out Of Range";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:53:37 by rpadasia          #+#    #+#             */
/*   Updated: 2026/07/01 12:53:40 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<long> numbers;
	if (!parseArgs(argc, argv, numbers))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	printContainer("Before: ", numbers);

	// --- std::vector ---
	std::vector<long> vecInput(numbers.begin(), numbers.end());
	struct timeval vecStart, vecEnd;
	gettimeofday(&vecStart, NULL);
	std::vector<long> vecSorted = PmergeMe::sortVector(vecInput);
	gettimeofday(&vecEnd, NULL);
	double vecTime = elapsedMicroseconds(vecStart, vecEnd);

	// --- std::deque ---
	std::deque<long> deqInput(numbers.begin(), numbers.end());
	struct timeval deqStart, deqEnd;
	gettimeofday(&deqStart, NULL);
	std::deque<long> deqSorted = PmergeMe::sortDeque(deqInput);
	gettimeofday(&deqEnd, NULL);
	double deqTime = elapsedMicroseconds(deqStart, deqEnd);

	printContainer("After: ", vecSorted);

	std::cout << "Time to process a range of " << numbers.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << numbers.size()
		<< " elements with std::deque : " << deqTime << " us" << std::endl;

	return 0;
}

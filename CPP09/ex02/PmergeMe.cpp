/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:51:55 by rpadasia          #+#    #+#             */
/*   Updated: 2026/07/01 23:16:58 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//self explanatorily
bool isPositiveInteger(const std::string &s, long &out)
{
	if (s.empty())
		return false;

	std::size_t idx = 0;
	if (s[0] == '+')
		idx = 1;
	if (idx == s.size())
		return false;

	for (std::size_t j = idx; j < s.size(); ++j)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[j])))
			return false;
	}

	errno = 0;
	char *endptr = NULL;
	long val = std::strtol(s.c_str(), &endptr, 10);
	if (errno == ERANGE || *endptr != '\0')
		return false;
	if (val <= 0 || val > INT_MAX)
		return false;

	out = val;
	return true;
}

//loops argv with the upstairs
bool parseArgs(int argc, char **argv, std::vector<long> &numbers)
{
	for (int i = 1; i < argc; ++i)
	{
		long val;
		if (!isPositiveInteger(argv[i], val))
			return false;
		numbers.push_back(val);
	}
	return !numbers.empty();
}

//kid named philosophers
double elapsedMicroseconds(const struct timeval &start, const struct timeval &end)
{
	double sec = static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0;
	double usec = static_cast<double>(end.tv_usec - start.tv_usec);
	return sec + usec;
}

//builds da Jacobsthal sequence, emits the indices bounding each binary search.
std::vector<std::size_t> PmergeMe::jacobsthalOrder(std::size_t m)
{
	std::vector<std::size_t> order;
	if (m < 2)
		return order;

	std::vector<std::size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < m)
	{
		std::size_t n = jacob.size();
		std::size_t next = jacob[n - 1] + 2 * jacob[n - 2];
		jacob.push_back(next);
	}

	std::size_t prevBound = 1; // b1 already placed by the caller
	for (std::size_t t = 2; t < jacob.size(); ++t)
	{
		std::size_t bound = (jacob[t] < m) ? jacob[t] : m;
		//"Where does the current Jacobsthal group end?"
		//jacob[t] gives the raw next boundary number (1, 3, 5, 11...),
		//but if it overshoots the number of pairs we actually have (m),
		//we cap it at m. So bound is always the highest follower index in the current group.
		for (std::size_t idx = bound; idx > prevBound; --idx)
			order.push_back(idx);
		prevBound = bound;
		if (bound >= m)
			break;
	}
	return order;
}

static bool pairFirstLess(const std::pair<long, long> &a, const std::pair<long, long> &b)
{
	return a.first < b.first;
}

std::vector<long> PmergeMe::fordJohnsonVector(std::vector<long> arr)
{
	std::size_t n = arr.size();
	if (n < 2)
		return arr;

	bool hasOdd = (n % 2 != 0);
	long oddOne = 0;
	// 0. split the straghgler
	if (hasOdd)
	{
		oddOne = arr.back();
		arr.pop_back();
	}

	// 1. Pair consecutive elements: .first = larger, .second = smaller.
	std::vector<std::pair<long, long> > pairs;
	pairs.reserve(arr.size() / 2);
	for (std::size_t i = 0; i < arr.size(); i += 2)
	{
		long a = arr[i];
		long b = arr[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	// 2. Recursively sort the "large" elements: this becomes the main chain.
	std::vector<long> larges;
	larges.reserve(pairs.size());
	for (std::size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].first);
	std::vector<long> mainChain = fordJohnsonVector(larges);

	// 3. Recover, for each pair, its rank among the larges (same order as
	//    mainChain, since both are correct ascending sorts of the same
	//    multiset of values).
	std::vector<std::pair<long, long> > sortedPairs(pairs);
	std::stable_sort(sortedPairs.begin(), sortedPairs.end(), pairFirstLess);

	std::vector<long> chain(mainChain);
	std::size_t m = sortedPairs.size();

	// 4. b1's partner always goes to the very front.
	if (m >= 1)
		chain.insert(chain.begin(), sortedPairs[0].second);

	// 5. Insert the remaining smalls in Jacobsthal order. Each one only
	//    needs to be searched up to the position of its own large partner,
	//    which is already in the chain -- that bound is what makes this
	//    "merge-insertion" instead of a naive insertion sort.
	std::vector<std::size_t> order = jacobsthalOrder(m);
	for (std::size_t k = 0; k < order.size(); ++k)
	{
		std::size_t idx = order[k];
		long largeVal = sortedPairs[idx - 1].first;
		long smallVal = sortedPairs[idx - 1].second;

		std::vector<long>::iterator boundIt = std::lower_bound(chain.begin(), chain.end(), largeVal);
		std::vector<long>::iterator insertIt = std::upper_bound(chain.begin(), boundIt, smallVal);
		chain.insert(insertIt, smallVal);
	}

	// 6. Leftover odd element (if any) is inserted last, unbounded.
	if (hasOdd)
	{
		std::vector<long>::iterator insertIt = std::upper_bound(chain.begin(), chain.end(), oddOne);
		chain.insert(insertIt, oddOne);
	}

	return chain;
}

std::vector<long> PmergeMe::sortVector(const std::vector<long> &input)
{
	return fordJohnsonVector(input);
}

//duplicated, not templated
std::deque<long> PmergeMe::fordJohnsonDeque(std::deque<long> arr)
{
	std::size_t n = arr.size();
	if (n < 2)
		return arr;

	bool hasOdd = (n % 2 != 0);
	long oddOne = 0;
	if (hasOdd)
	{
		oddOne = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<long, long> > pairs;
	for (std::size_t i = 0; i < arr.size(); i += 2)
	{
		long a = arr[i];
		long b = arr[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	std::deque<long> larges;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].first);
	std::deque<long> mainChain = fordJohnsonDeque(larges);

	std::deque<std::pair<long, long> > sortedPairs(pairs);
	std::stable_sort(sortedPairs.begin(), sortedPairs.end(), pairFirstLess);

	std::deque<long> chain(mainChain);
	std::size_t m = sortedPairs.size();

	if (m >= 1)
		chain.insert(chain.begin(), sortedPairs[0].second);

	std::vector<std::size_t> order = jacobsthalOrder(m);
	for (std::size_t k = 0; k < order.size(); ++k)
	{
		std::size_t idx = order[k];
		long largeVal = sortedPairs[idx - 1].first;
		long smallVal = sortedPairs[idx - 1].second;

		std::deque<long>::iterator boundIt = std::lower_bound(chain.begin(), chain.end(), largeVal);
		std::deque<long>::iterator insertIt = std::upper_bound(chain.begin(), boundIt, smallVal);
		chain.insert(insertIt, smallVal);
	}

	if (hasOdd)
	{
		std::deque<long>::iterator insertIt = std::upper_bound(chain.begin(), chain.end(), oddOne);
		chain.insert(insertIt, oddOne);
	}

	return chain;
}

std::deque<long> PmergeMe::sortDeque(const std::deque<long> &input)
{
	return fordJohnsonDeque(input);
}

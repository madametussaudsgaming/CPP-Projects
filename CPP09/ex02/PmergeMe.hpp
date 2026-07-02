#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <cctype>
#include <sys/time.h>

class PmergeMe
{
public:
	static std::vector<long>	sortVector(const std::vector<long> &input);
	static std::deque<long>		sortDeque(const std::deque<long> &input);
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

private:

	static std::vector<long>		fordJohnsonVector(std::vector<long> arr);
	static std::deque<long>			fordJohnsonDeque(std::deque<long> arr);
	static std::vector<std::size_t>	jacobsthalOrder(std::size_t m);
};

// Template must be defined in the header so each translation unit can instantiate it.
template <typename Container>
void printContainer(const std::string &label, const Container &c)
{
	std::cout << label;
	typename Container::const_iterator it = c.begin();
	for (; it != c.end(); ++it)
	{
		std::cout << *it;
		typename Container::const_iterator next = it;
		++next;
		if (next != c.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

bool	parseArgs(int argc, char **argv, std::vector<long> &numbers);
bool	isPositiveInteger(const std::string &s, long &out);
double	elapsedMicroseconds(const struct timeval &start, const struct timeval &end);

#endif

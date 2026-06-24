/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:44:45 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/24 20:40:43 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <list>
#include <cstdlib>
#include <deque>
#include <ctime>
#include <map>

class BitcoinExchange {
	private:
		std::string		_date;
		float			_value;
		std::map<std::string, float> _btcData;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void fillValues(std::string lineData);

};

#endif

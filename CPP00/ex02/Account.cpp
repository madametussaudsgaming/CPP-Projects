/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 00:20:06 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/09 21:06:23 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	int nbacc = Account::getNbAccounts();
	int total = Account::getTotalAmount();
	int nbdep = Account::getNbDeposits();
	int nbwdr = Account::getNbWithdrawals();
	_displayTimestamp();
	std::cout<<"accounts:"<<nbacc<<";total:"<<total<<";deposits:"<<nbdep<<";withdrawals:"<<nbwdr<<std::endl;
}


Account::Account( int initial_deposit )
{
	_accountIndex =_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount = _totalAmount + _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<initial_deposit<<";created"<<std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits += 1;
	_nbDeposits += 1;
	_displayTimestamp();
	std::cout	<<"index:"<<_accountIndex<<";p_amount:"
				<<_amount<<";deposit:"<<deposit<<";amount:"
				<<(_amount + deposit)<<";nb_deposits:"<<_nbDeposits<<std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout<<"refused"<<std::endl;
		return (false);
	}
	else
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout<<withdrawal<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<<"index:"<<_accountIndex
				<<";amount:"<<_amount
				<<";deposits:"<<_nbDeposits
				<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}



void Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);
	std::cout	<<"["
				<<(now->tm_year+1900)
				<< std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
				<< std::setw(2) << now->tm_mday
				<< "_"
				<< std::setw(2) << now->tm_hour
				<< std::setw(2) << now->tm_min
				<< std::setw(2) << now->tm_sec
				<< "] "; 
}
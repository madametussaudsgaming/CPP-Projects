/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:04 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/01 17:27:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

class Bureaucrat{
	const std::string name = "DEFAULT";
	int			grade;
	
	Bureaucrat();
	Bureaucrat(int initGrade);
	Bureaucrat(const Bureaucrat& ori);
	Bureaucrat& operator=(const Bureaucrat ori);
	~Bureaucrat();

	char	getName();
	int		getGrade();
	void	incrementGrade();
	void	decrementGrade();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& gradeName);

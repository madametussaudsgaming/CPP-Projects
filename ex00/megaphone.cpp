/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:04:32 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/04 18:04:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int is_lower(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	int i = 1;
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			if (is_lower(argv[i][j]))
				std::cout<<(char(argv[i][j] - 32));
			else
				std::cout<<(argv[i][j]);
			j++;
		}
		i++;
	}
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout<<"\n";
}
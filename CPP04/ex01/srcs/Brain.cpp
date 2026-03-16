/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:06:21 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 20:27:04 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain::Default Constructor called!"<<std::endl;
	RandomIdeas();
}

Brain::Brain(const Brain &ori)
{
	std::cout<<"Brain::Copy Constructor called!"<<std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ori.ideas[i];
}

Brain &Brain::operator=(const Brain &ori)
{
	std::cout<<"Brain::Copy Assignment Operator called!"<<std::endl;
	if (this == &ori)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ori.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout<<"Brain::Destructor called!"<<std::endl;
}

void Brain::RandomIdeas()
{
	const std::string random[] = {
		"You like Huey Lewis and the News?",
		"Um, they're okay.",
		"Their early work was a little too new wave for my taste.",
		"But when Sports came out in '83, I think they really came into their own, commercially and artistically.",
		"The whole album has a clear, crisp sound, and a new sheen of consummate professionalism that really gives the songs a big boost.",
		"He's been compared to Elvis Costello, but I think Huey has a far more bitter, cynical sense of humor.",
		"Hey, Halberstram?",
		"Yes, Allen?",
		"Why are there copies of the Style section all over the place?",
		"Do you... Do you have a dog? A little chow or something?",
		"No, Allen.",
		"Is that a raincoat?",
		"Yes, it is. In '87, Huey released this; Fore!, their most accomplished album.",
		"I think their undisputed masterpiece is 'Hip To Be Square'.",
		"A song so catchy, most people probably don't listen to the lyrics.",
		"But they should, because it's not just about the pleasures of conformity and the importance of trends.",
		"It's also a personal statement about the band itself.",
		"Hey, Paul!",
		"Try getting a reservation at Dorsia now, you friggin' stupid bastard!"
	};
	for (int i = 0; i < 100; i++)
		this->ideas[i] = random[rand()%19];
}
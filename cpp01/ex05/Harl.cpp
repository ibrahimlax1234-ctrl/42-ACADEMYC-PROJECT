/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:51:56 by librahim          #+#    #+#             */
/*   Updated: 2025/05/10 23:34:06 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "Harl : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Harl : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Harl : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "Harl : This is unacceptable ! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level)
{
	void			(Harl::*ptr_member[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string 	s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	i = 0;
	while(i < 4)
	{
		if (s[i].compare(level) == 0)
		{
			(this->*ptr_member[i])();
			break ;
		}
		i++;
	}
}

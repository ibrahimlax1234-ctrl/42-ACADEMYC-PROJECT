/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:48:59 by librahim          #+#    #+#             */
/*   Updated: 2025/05/09 20:53:02 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	p;
	std::string	line;

	std::cout << "WELCOME TO THE AWESOME PHONEBOOK SOFTWARE." << std::endl << std::endl;
	while (1)
	{
		if (std::cin.eof())
        	return 1;
		std::cout << "Enter ADD or SEARCH or EXIT : ";
		std::getline(std::cin, line);
		if (line.compare("ADD") == 0)
			p.do_add();
		else if (line.compare("SEARCH") == 0)
		{
			system("clear");
			p.do_search();
		}
		else if (line.compare("EXIT") == 0)
		{
			system("clear");
			std::cout << "Thanks for using the awesome PhoneBook software.\nGoodbye !"<< std::endl;
			break ;
		}
		else
			system("clear");
	}
	return 0;
}

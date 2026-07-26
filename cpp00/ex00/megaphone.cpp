/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:59:34 by librahim          #+#    #+#             */
/*   Updated: 2025/05/09 20:07:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int ac, char  *av[])
{
	int	i = 1;
	int j;
	std::string tmp;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		j = 0;
		tmp = av[i];
		while (j < (int) tmp.size())
		{
			std::cout << (char) std::toupper(tmp.at(j));
			j++;
		}
		i++;
	}
	return 0;
}

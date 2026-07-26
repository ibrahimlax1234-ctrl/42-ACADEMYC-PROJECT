/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:39:32 by librahim          #+#    #+#             */
/*   Updated: 2025/05/13 04:42:31 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
    Zombie	*ret = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		ret[i].set_zombie_name(name);
		i++;
	}
	return ret;
}

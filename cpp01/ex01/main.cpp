/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:39:18 by librahim          #+#    #+#             */
/*   Updated: 2025/05/14 08:11:45 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    
    int size = 5;
    Zombie *zs = zombieHorde(size, "heap zombie NPC");
    if (zs == NULL)
    {
        std::cout << "Bad allocation" <<std::endl;
        return 1;
    }
    int i = 0;
    while (i < size)
    {
        zs[i].announce();
        i++;
    }
    delete[] zs;
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:53:03 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 23:47:29 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{

    FragTrap f("Fragy");

    f.attack("none");

    f.takeDamage(30);

    f.beRepaired(20);

    f.highFivesGuys();

    FragTrap edge("Edgy");

    for (int i = 0; i < 100; ++i)
        edge.attack("Wall");

    edge.highFivesGuys();

    edge.takeDamage(999);

    edge.highFivesGuys();
    edge.attack("Ghost");
    edge.beRepaired(50);
    FragTrap g(f);
    edge = g;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:53:03 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 23:46:32 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("bot a");

    a.attack("you");

    a.takeDamage(30);

    a.beRepaired(20);

    a.guardGate();


    ScavTrap b("edgebot");

    for (int i = 0; i < 50; ++i) {
        b.attack("the wall");
    }

    b.attack("the wall");

    b.beRepaired(10);

    b.takeDamage(100);

    b.attack("the wall");

    b.beRepaired(10);

    b.guardGate();

    b.takeDamage(10);
    ScavTrap c(b);
    a = b;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:07:30 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 23:45:38 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("BOT1");
    ClapTrap b("BOT2");
    a.attack("BOT2");
    b.takeDamage(1);
    b.beRepaired(1);
    ClapTrap c("BOT3");
    for (int i = 0; i < 10; ++i)
        c.attack("random bot");
    c.attack("random bot");
    c.beRepaired(5);
    ClapTrap d("BOT3");
    d.takeDamage(10);
    d.attack("Ghost");
    d.beRepaired(5);
    ClapTrap e(d);
    a = b;
    return 0;
}

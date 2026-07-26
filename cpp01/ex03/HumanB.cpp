/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:47:25 by librahim          #+#    #+#             */
/*   Updated: 2025/05/11 00:17:31 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nname)
{
    name = nname;
    w = NULL;
}

void    HumanB::setWeapon(Weapon& new_w)
{
    w = &new_w;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << w->getType() << std::endl;
}

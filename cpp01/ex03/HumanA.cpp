/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:47:20 by librahim          #+#    #+#             */
/*   Updated: 2025/05/11 00:17:40 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nname, Weapon& ww) : name(nname), w(ww)
{
    return ;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << w.getType() << std::endl;
}

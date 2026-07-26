/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:47:32 by librahim          #+#    #+#             */
/*   Updated: 2025/05/12 23:29:12 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(std::string ntype)
{
    type = ntype;
}

const std::string& Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string s)
{
    type = s;
}

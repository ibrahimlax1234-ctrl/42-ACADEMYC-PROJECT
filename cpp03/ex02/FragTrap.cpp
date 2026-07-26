/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:49:03 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 23:26:47 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default constructor of FragTrap has been called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(std::string n)
{
    std::cout << "Paramerized constructor of FragTrap has been called" << std::endl;
    name = n;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "Default destructor of FragTrap has been called" << std::endl;
}


FragTrap::FragTrap(const FragTrap& obj)
{
    std::cout << "Copy constructor of FragTrap has been called" << std::endl;
    name = obj.name;
    hit_points = obj.hit_points;
    energy_points = obj.energy_points;
    attack_damage = obj.attack_damage;
}

FragTrap&   FragTrap::operator=(const FragTrap& obj)
{
    std::cout << " A FragTrap copy assignement operator has been called" << std::endl;
    name = obj.name;
    hit_points = obj.hit_points;
    energy_points = obj.energy_points;
    attack_damage = obj.attack_damage;
    return *this;

}

void FragTrap::highFivesGuys(void)
{
    if (hit_points == 0 || energy_points == 0)
    {
        std::cout << "Fragtrap " << name << "cant high-five right now" <<std::endl;
        return ;
    }
    std::cout << "the fragtrap " << name << " is happily requesting highfives to everyone :)" << std::endl;
}

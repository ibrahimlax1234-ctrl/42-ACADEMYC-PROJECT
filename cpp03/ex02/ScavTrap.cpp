/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:29 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 23:26:25 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default constructor of ScavTrap has been called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(std::string n)
{
    std::cout << "Paramerized constructor of ScavTrap has been called" << std::endl;
    name = n;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Default destructor of ScavTrap has been called" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& obj)
{
    std::cout << "Copy constructor of ScavTrap has been called" << std::endl;
    name = obj.name;
    hit_points = obj.hit_points;
    energy_points = obj.energy_points;
    attack_damage = obj.attack_damage;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << " A scavtrap copy assignement operator has been called" << std::endl;
    name = obj.name;
    hit_points = obj.hit_points;
    energy_points = obj.energy_points;
    attack_damage = obj.attack_damage;
    return *this;
    
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points == 0)
    {
        std::cout << "Attack action from scavtrap " << name << " didnt work because this scavtrap is already dead he just doesnt know it" << std::endl;
        return ;
    }
    if (this->energy_points == 0)
    {
        std::cout << "Attack action from scavtrap didnt work because there is not enough energy points." << std::endl;
        return ;
    }
    std::cout << "Scavtrap " << name<<" attacks "<<target<< " causing " << this->attack_damage << " hit points." << std::endl;
    energy_points--;
}

void    ScavTrap::guardGate()
{
    if (hit_points == 0 || energy_points == 0)
    {
        std::cout << "Scavtrap " << name << "cant go into Gate keeper mode" <<std::endl;
        return ;
    }
    std::cout << "Scavtrap " << name << " is now in Gate keeper mode" <<std::endl;
}
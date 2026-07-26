/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:21:20 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 21:54:02 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor has been called" << std::endl;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}


ClapTrap::ClapTrap(std::string n)
{
    std::cout << "Paramerized constructor has been called" << std::endl;
    name = n;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Default destructor has been called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "Copy constructor has been called" << std::endl;
    name = obj.name;
    hit_points = obj.hit_points;
    energy_points = obj.energy_points;
    attack_damage = obj.attack_damage;
}


ClapTrap&   ClapTrap::operator=(const ClapTrap& obj)
{
    std::cout << "Copy assignement operator has been called" << std::endl;
    name = obj.name;
    hit_points = obj.hit_points;
    energy_points = obj.energy_points;
    attack_damage = obj.attack_damage;
    return *this;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points == 0)
    {
        std::cout << "Attack action from claptrap " << name << " didnt work because this claptrap is already dead" << std::endl;
        return ;
    }
    if (this->energy_points == 0)
    {
        std::cout << "Attack action from claptrap "<<name<<" didnt work because there is not enough energy points." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name<<" attacks "<<target<< " causing " << this->attack_damage << " hit points." << std::endl;
    energy_points--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name <<" has taken " << amount << " damage." << std::endl;
    if (amount > hit_points)
    {
        hit_points = 0;
        return ;
    }
    else
        hit_points = hit_points - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
        if (this->hit_points == 0)
    {
        std::cout << "Repair action didnt work on claptrap " << name << " because this claptrap is already dead" << std::endl;
        return ;
    }
    if (this->energy_points == 0)
    {
        std::cout << "Repair action didnt work because there is not enough energy points." << std::endl;
        return ;
    }
    hit_points = hit_points + amount;
    std::cout << "ClapTrap " << name<<" has repaired itself and gained " << amount << " of hit points." << std::endl;
    energy_points--;
}

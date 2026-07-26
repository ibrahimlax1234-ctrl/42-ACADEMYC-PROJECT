/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:54:30 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 21:53:30 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    protected :
        std::string             name;
        unsigned int            hit_points;
        unsigned int            energy_points;
        unsigned int            attack_damage;

    public :
        ClapTrap();
        ClapTrap(std::string n);
        ClapTrap(const ClapTrap& obj);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap&   operator=(const ClapTrap& obj);
    
};

#endif
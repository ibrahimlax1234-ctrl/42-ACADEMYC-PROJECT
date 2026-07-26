/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:56:21 by librahim          #+#    #+#             */
/*   Updated: 2025/05/18 22:10:00 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(std::string n);
        ~ScavTrap();
        ScavTrap(const ScavTrap& obj);
        ScavTrap&   operator=(const ScavTrap& obj);
        void    attack(const std::string& target);
        void    guardGate();
};

#endif
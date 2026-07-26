/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:47:27 by librahim          #+#    #+#             */
/*   Updated: 2025/05/14 08:14:35 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP 
# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
    private :
        std::string name;
        Weapon      *w;
    public :
        HumanB(std::string nname);
        void    setWeapon(Weapon& new_w);
        void    attack();
};

#endif
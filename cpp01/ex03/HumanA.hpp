/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:47:23 by librahim          #+#    #+#             */
/*   Updated: 2025/05/14 08:14:37 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <iostream> 
# include <string>

class HumanA
{
    private :
        std::string name;
        Weapon&     w;
    public :
        HumanA(std::string nname, Weapon& ww);
        void    attack();
};

#endif
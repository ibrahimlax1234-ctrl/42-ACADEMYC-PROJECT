/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:47:34 by librahim          #+#    #+#             */
/*   Updated: 2025/05/14 08:14:35 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string> 

class Weapon
{

    
    private :
        std::string type;



    public :
        Weapon(std::string ntype);
        const std::string& getType();
        void        setType(std::string s);
    
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:10:36 by librahim          #+#    #+#             */
/*   Updated: 2025/05/14 08:09:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string n);
        ~Zombie(void);
        void announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
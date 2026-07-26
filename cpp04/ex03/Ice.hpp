/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:22:58 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 00:31:52 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
    public :
        Ice();
        ~Ice();
        Ice(const   Ice& o);
        Ice&        operator=(const Ice& o);
        AMateria*   clone() const;
        void use(ICharacter& target);
};


#endif
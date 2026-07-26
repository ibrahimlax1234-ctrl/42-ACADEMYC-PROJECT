/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:28:06 by librahim          #+#    #+#             */
/*   Updated: 2025/05/22 21:28:40 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"


class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        virtual ~AMateria();
        AMateria& operator=(const AMateria&  o);
        AMateria(const AMateria&  o);
        AMateria(std::string const & type);
        std::string const& getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
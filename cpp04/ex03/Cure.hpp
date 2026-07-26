/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:16:22 by librahim          #+#    #+#             */
/*   Updated: 2025/05/22 21:38:20 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure();
        ~Cure();
        Cure(const   Cure& o);
        Cure&        operator=(const Cure& o);

        AMateria*   clone() const;
        void use(ICharacter& target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:25:08 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:04:44 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private :
        AMateria*   ms[4];
    public :
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& ob);
        MateriaSource& operator=(const MateriaSource& ob);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
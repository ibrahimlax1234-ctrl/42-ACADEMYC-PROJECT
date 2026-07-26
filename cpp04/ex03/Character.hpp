/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:21:24 by librahim          #+#    #+#             */
/*   Updated: 2025/05/22 19:25:16 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character : public ICharacter
{
    private:
        std::string name;
        AMateria*   m[4];
    public :
        Character();
        ~Character();
        Character(const Character& o);
        Character& operator=(const Character& o);

        Character(std::string name);


        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
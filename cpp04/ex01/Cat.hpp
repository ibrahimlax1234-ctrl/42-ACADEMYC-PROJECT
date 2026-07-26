/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:22:35 by librahim          #+#    #+#             */
/*   Updated: 2025/05/21 18:42:07 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

#include <string>
#include <iostream>
#include "Brain.hpp"


class Cat : public Animal
{
        private :
                Brain*  b;
        public :
                Cat();
                ~Cat();
                Cat(const Cat& obj);
                Cat&            operator=(const Cat& obj);
                void            makeSound() const;
                std::string     getType() const;
                void            express_an_idea(int i);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:22:35 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:13:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "AAnimal.hpp"

#include <string>
#include <iostream>
#include "Brain.hpp"


class Cat : public AAnimal
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
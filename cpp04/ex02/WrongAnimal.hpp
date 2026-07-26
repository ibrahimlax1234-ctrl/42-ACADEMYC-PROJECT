/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:29:04 by librahim          #+#    #+#             */
/*   Updated: 2025/05/20 22:15:19 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class WrongAnimal
{
    protected :
        std::string type;
    public :
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal& obj);
        WrongAnimal&         operator=(const WrongAnimal& obj);
        void    makeSound() const;
        std::string getType() const;
};

#endif
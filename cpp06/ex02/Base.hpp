/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:04:55 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 20:34:56 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP


#include <iostream>
#include <cstdlib>
#include <ctime>


class  Base
{
    public:
    
    virtual ~Base();
};

void identify(Base* p);
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif

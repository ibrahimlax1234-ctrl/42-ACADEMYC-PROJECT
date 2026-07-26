/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:49:22 by librahim          #+#    #+#             */
/*   Updated: 2025/05/21 18:48:45 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    private :
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& obj);
        Brain&          operator=(const Brain& obj);
        void            set_ideas(std::string ss);
        std::string     get_idea(int i);

};
#endif
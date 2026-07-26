/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:54:09 by librahim          #+#    #+#             */
/*   Updated: 2025/05/10 23:36:42 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl    h;



    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("ERROR");
    h.complain("WARNING");


    return 0;
}

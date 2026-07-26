/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:41:36 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 20:55:18 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    std::srand(std::time(NULL));


    std::cout << "Generating a type ..." << std::endl;
    Base *ptr = generate();


    
    std::cout << "Identifiqation of the type generated (as pointer): " << std::endl;
    identify(ptr);
    std::cout << "Identifiqation of the type generated (as reference): " << std::endl;
    identify(*ptr);
    return 0;
}
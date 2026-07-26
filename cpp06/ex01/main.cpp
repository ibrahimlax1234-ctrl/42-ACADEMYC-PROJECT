/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:54:05 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 20:30:37 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d;
    d.z=57;
    d.l=78;
    d.q= "hellohello";

        Data *d_ptr = &d;
        std::cout << "printing member :" <<std::endl;
        std::cout << "integer z: " << d.z << std::endl;
        std::cout << "integer l: " << d_ptr->l << std::endl;
        std::cout << "string q: " << d_ptr->q << std::endl;
        uintptr_t int_ptr_form = Serializer::serialize(d_ptr);
        std::cout << "pointer in integer form : " << int_ptr_form << std::endl;
        Data* back = Serializer::deserialize(int_ptr_form);
        std::cout << "printing member after serilize and deserialize:" <<std::endl;
        std::cout << "integer z: " << back->z << std::endl;
        std::cout << "integer l: " << back->l << std::endl;
        std::cout << "string q: " << back->q << std::endl;
    
    return 0;
}

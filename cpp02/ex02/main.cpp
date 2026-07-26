/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:00:59 by librahim          #+#    #+#             */
/*   Updated: 2025/05/15 15:05:08 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a,b) << std::endl;
    return 0;
}

// int main()
// {
//     Fixed f1(5); 
//     Fixed f2(3.14f);
//     Fixed f3(2);
//     Fixed f4(6.28f);

//     Fixed sum = f1 + f2;
//     std::cout << "f1 + f2 = " << sum.toFloat() << std::endl;

//     Fixed diff = f1 - f3;
//     std::cout << "f1 - f3 = " << diff.toFloat() << std::endl;

//     Fixed prod = f2 * f3;
//     std::cout << "f2 * f3 = " << prod.toFloat() << std::endl;

//     Fixed quot = f4 / f3;
//     std::cout << "f4 / f3 = " << quot.toFloat() << std::endl;

//     std::cout << "f1 < f2: " << (f1 < f2) << std::endl;

//     std::cout << "f1 > f3: " << (f1 > f3) << std::endl;

//     std::cout << "f1 <= f3: " << (f1 <= f3) << std::endl;

//     std::cout << "f2 >= f4: " << (f2 >= f4) << std::endl;

//     std::cout << "f1 == f3: " << (f1 == f3) << std::endl;

//     std::cout << "f2 != f4: " << (f2 != f4) << std::endl;

//     std::cout << "f1 before prefix increment: " << f1.toFloat() << std::endl;
//     ++f1;
//     std::cout << "f1 after prefix increment: " << f1.toFloat() << std::endl;

//     std::cout << "f2 before postfix increment: " << f2.toFloat() << std::endl;
//     Fixed tmp1 = f2++;
//     std::cout << "tmp1 (postfix increment result): " << tmp1.toFloat() << std::endl;
//     std::cout << "f2 after postfix increment: " << f2.toFloat() << std::endl;

//     std::cout << "f3 before prefix decrement: " << f3.toFloat() << std::endl;
//     --f3;
//     std::cout << "f3 after prefix decrement: " << f3.toFloat() << std::endl;

//     std::cout << "f4 before postfix decrement: " << f4.toFloat() << std::endl;
//     Fixed tmp2 = f4--;
//     std::cout << "tmp2 (postfix decrement result): " << tmp2.toFloat() << std::endl;
//     std::cout << "f4 after postfix decrement: " << f4.toFloat() << std::endl;

//     Fixed& minNonConst = Fixed::min(f1, f2);
//     std::cout << "Min (non-const) between f1 and f2: " << minNonConst.toFloat() << std::endl;

//     Fixed& maxNonConst = Fixed::max(f1, f2);
//     std::cout << "Max (non-const) between f1 and f2: " << maxNonConst.toFloat() << std::endl;

//     return 0;
// }
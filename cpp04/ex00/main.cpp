/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:45:38 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:18:28 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"

int main()
{
    Animal aa;
    Animal ab;
    ab = aa;
    Animal ac = aa;
    ac.makeSound();

    Cat ca;
    Cat cb;
    cb = ca;
    Cat cc = ca;
    cc.makeSound();


    Dog da;
    Dog db;
    db = da;
    Dog dc = da;
    dc.makeSound();


    Animal *h_aa = new Animal();
    Animal *h_ab = new Animal(*h_aa);
    *h_aa = *h_ab;
    h_aa->makeSound();
    delete h_aa;
    delete h_ab;


    Cat *h_ca = new Cat();
    Cat *h_cb = new Cat(*h_ca);
    *h_ca = *h_cb;
    h_ca->makeSound();
    delete h_ca;
    delete h_cb;


    Dog *h_da = new Dog();
    Dog *h_db = new Dog(*h_da);
    h_da->makeSound();
    *h_da = *h_db;
    delete h_da;
    delete h_db;


    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;

    const WrongAnimal* w_j = new WrongCat();
    std::cout << w_j->getType() << std::endl;
    w_j->makeSound();
    delete w_j;

    return 1;
}

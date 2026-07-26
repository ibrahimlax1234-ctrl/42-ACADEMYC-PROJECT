/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:45:38 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:13:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"

int main()
{
    Cat ca;
    Cat cb;
    cb = ca;
    Cat cc = ca;
    cc.makeSound();
    cc.express_an_idea(4);



    Cat *h_ca = new Cat();
    Cat *h_cb = new Cat(*h_ca);
    *h_ca = *h_cb;
    h_ca->makeSound();
    h_ca->express_an_idea(4);
    delete h_ca;
    delete h_cb;



    Dog da;
    Dog db;
    db = da;
    Dog dc = da;
    dc.makeSound();
    dc.express_an_idea(4);



    Dog *h_da = new Dog();
    Dog *h_db = new Dog(*h_da);
    h_da->makeSound();
    *h_da = *h_db;
    h_da->express_an_idea(4);
    delete h_da;
    delete h_db;



    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    delete i;
    delete j;




    const WrongAnimal* w_j = new WrongCat();
    std::cout << w_j->getType() << std::endl;
    w_j->makeSound();
    delete w_j;

    int size = 6;

    int ii = 0;
    AAnimal *a[size];
    while (ii < size/2)
    {
        a[ii] = new Dog();
        ii++;
    }

    ii = size/2;
    while (ii < size)
    {
        a[ii] = new Cat();
        ii++;
    }
    ii = -1;
    while (++ii < size/2)
        a[ii]->makeSound();
    ii--;
    while (++ii < size)
        a[ii]->makeSound();
    ii = -1;
    while (++ii < size)
        delete a[ii];





    Cat *cat_a = new Cat();
    Cat *cat_b = new Cat();
    *cat_a = *cat_b;
    delete cat_a;
    cat_b->express_an_idea(74);
    delete cat_b;




    Dog *dog_a = new Dog();
    Dog *dog_b = new Dog();
    *dog_a = *dog_b;
    delete dog_a;
    dog_b->express_an_idea(74);
    delete dog_b;



    
    return 0;
}

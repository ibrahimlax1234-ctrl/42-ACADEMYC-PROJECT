/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:46:34 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 03:16:11 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <string>
#include "MateriaSource.hpp"
#include <iostream>

void f(){system("leaks ex03");}

int main()
{
        atexit(f);
        // AMateria *sa = new Ice();
        // AMateria *sv = new Cure();
        // AMateria *svc = new Ice();
        // AMateria *svv = new Cure();


        // Character *a = new Character("bob");
        // Character *b = new Character("target");

        // ICharacter *ia = new Character("ibob");
        // ICharacter *ib = new Character("itarget");

        // AMateria *saa = new Ice();
        // AMateria *svvd = new Cure();
        // AMateria *svcc = new Ice();
        // AMateria *svvv = new Cure();

        // ia->equip(saa);
        // ia->equip(svvd);
        // ia->equip(svcc);
        // ia->equip(svvv);

        // a->use(0, *ib);
        // a->use(1, *ib);
        // a->use(2, *ib);
        // a->use(3, *ib);

        // *ib = *ia;

        // a->equip(sa);
        // a->equip(sv);
        // a->equip(svc);
        // a->equip(svv);

        // a->use(0, *b);
        // a->use(1, *b);
        // a->use(2, *b);
        // a->use(3, *b);

        // Character *copy_a = new Character(*a);

        // copy_a->use(0, *b);
        // copy_a->use(1, *b);
        // copy_a->use(2, *b);
        // copy_a->use(3, *b);
        

        // *b = *a;

        // b->use(0, *a);
        // b->use(1, *a);
        // b->use(2, *a);
        // b->use(3, *a);
        // a->unequip(0);

        // delete sa;
        // delete a;
        // delete b;
        // delete copy_a;
        // delete ib;
        // delete ia;
        

        MateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;

        return 1;
}


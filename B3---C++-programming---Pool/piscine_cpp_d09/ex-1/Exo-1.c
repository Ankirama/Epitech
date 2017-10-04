//
//  Exo-1.c
//  ex-1
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Exo-1.h"

static void KoalaInitializer(t_koala* this, char* _name, char _isALegend)
{
    printf("----\n");
    this->m_isALegend = _isALegend;
    printf("Building Cthulhu\n");
    this->m_parent.name = strdup(_name);
    this->m_parent.m_power = _isALegend == 1 ? 42 : 0;
    printf("Building %s\n", _name);
}

static void CthulhuInitializer(t_cthulhu* this)
{
    printf("----\n");
    this->m_power = 42;
    this->name = "Cthulhu";
    printf("Building Cthulhu\n");
}

t_cthulhu*      NewCthulhu()
{
    t_cthulhu   *new;
    
    new = malloc(sizeof(t_cthulhu));
    CthulhuInitializer(new);
    return (new);
}

void            PrintPower(t_cthulhu* this)
{
    printf("Power => %d\n", this->m_power);
}

void            Attack(t_cthulhu* this)
{
    if (this->m_power >= 42)
    {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->name);
    }
    else
        printf("%s can't attack, he doesn't have enough power\n", this->name);
}

void            Sleeping(t_cthulhu* this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->name);
}

t_koala*        NewKoala(char* name, char _isALegend)
{
    t_koala     *new;
    
    new = malloc(sizeof(t_koala));
    KoalaInitializer(new, name, _isALegend);
    return (new);
}

void            Eat(t_koala* this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.name);
}

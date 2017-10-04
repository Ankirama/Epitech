//
//  Exo-1.h
//  ex-1
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __ex_1__Exo_1__
#define __ex_1__Exo_1__

typedef struct  s_cthulhu {
    int         m_power;
    char        *name;
}               t_cthulhu;

t_cthulhu*      NewCthulhu();
void            PrintPower(t_cthulhu* this);
void            Attack(t_cthulhu* this);
void            Sleeping(t_cthulhu* this);

typedef struct  s_koala {
    t_cthulhu   m_parent;
    char        m_isALegend;
}               t_koala;

t_koala*        NewKoala(char* name, char _isALegend);
void            Eat(t_koala* this);

t_cthulhu*      NewCthulhu();
t_koala*        NewKoala(char *name, char _isALegend);


#endif /* defined(__ex_1__Exo_1__) */

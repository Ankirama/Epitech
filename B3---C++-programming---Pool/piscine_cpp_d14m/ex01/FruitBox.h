//
//  FruitBox.h
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d14m__FruitBox__
#define __piscine_cpp_d14m__FruitBox__

#include "Fruit.h"
#include "FruitNode.h"

class FruitBox {
public:
    FruitBox(int);
    ~FruitBox();
    
    int nbFruits() const;
    bool putFruit(Fruit* f);
    Fruit* pickFruit();
    FruitNode* head() const;
private:
    int         m_size;
    int         m_nbrFruits;
    FruitNode   *m_list;
};

#endif /* defined(__piscine_cpp_d14m__FruitBox__) */

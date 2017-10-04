//
//  FruitNode.h
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d14m_FruitNode_h
#define piscine_cpp_d14m_FruitNode_h

#include "Fruit.h"

typedef struct          s_FruitNode {
    Fruit         *fruit;
    struct s_FruitNode  *next;
}                       FruitNode;

#endif

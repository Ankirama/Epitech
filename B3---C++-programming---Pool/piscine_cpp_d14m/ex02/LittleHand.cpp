//
//  LittleHand.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "LittleHand.h"

void LittleHand::sortFruitBox(FruitBox& unsorted,
                              FruitBox& lemons,
                              FruitBox& bananas,
                              FruitBox& limes) {
    FruitBox    tmp(unsorted.nbFruits());
    Fruit       *fruit;
    while ((fruit = unsorted.pickFruit())) {
        if (fruit->getName() == "lemon") {
            if (!lemons.putFruit(fruit))
                tmp.putFruit(fruit);
        }
        else if (fruit->getName() == "lime") {
            if (!limes.putFruit(fruit))
                tmp.putFruit(fruit);
        }
        else if (fruit->getName() == "banana") {
            if (!bananas.putFruit(fruit))
                tmp.putFruit(fruit);
        }
        else
            tmp.putFruit(fruit);
    }
    while ((fruit = tmp.pickFruit())) {
        unsorted.putFruit(fruit);
    }
}

FruitBox* const * LittleHand::organizeCoconut(Coconut const * const * coconuts_packet) {
    int                     size;
    int                     i;
    FruitBox                **pack;
    
    size = 0;
    i = -1;
    while (coconuts_packet[++i] != 0)
        ++size;
    size = size % 6 == 0 ? size / 6 : size / 6 + 1;
    pack = new FruitBox* [size + 2];
    for (int j = 0; j < size + 2; ++j) {
        pack[j] = new FruitBox(6);
    }
    i = -1;
    while (coconuts_packet[++i])
        pack[i / 6]->putFruit(const_cast<Coconut *>(coconuts_packet[i % 6]));
    return  pack;
}
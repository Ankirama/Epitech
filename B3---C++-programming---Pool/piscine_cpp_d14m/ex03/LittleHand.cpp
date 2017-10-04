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
    Fruit const       *fruit;
    while (unsorted.head() != 0) {
        fruit = unsorted.pickFruit();
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
    while (tmp.head() != 0) {
        unsorted.putFruit(tmp.pickFruit());
    }
}

FruitBox* const * LittleHand::organizeCoconut(Coconut const * const * coconuts_packet) {
    Coconut const * const   *tmp;
    int                     size;
    int                     i;
    FruitBox* const         *pack;
    
    size = 0;
    i = -1;
    tmp = coconuts_packet;
    while (tmp[++i] != 0)
        ++size;
    size = size % 6 == 0 ? size / 6 : size / 6 + 1;
    pack = new FruitBox* [size];
    i = -1;
    while (tmp[++i] != 0)
        pack[i / 6]->putFruit(tmp[i % 6]);
    return  pack;
}


void Mixer::plugMixer(MixerBase& mixer) {
    Mixer mix = Mixer();
    mixer = mix;
}
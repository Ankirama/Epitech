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
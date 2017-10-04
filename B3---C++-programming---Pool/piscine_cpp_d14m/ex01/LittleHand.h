//
//  LittleHand.h
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d14m__LittleHand__
#define __piscine_cpp_d14m__LittleHand__

#include "FruitBox.h"

class LittleHand {
public:
    static void sortFruitBox(FruitBox& unsorted,
                             FruitBox& lemons,
                             FruitBox& bananas,
                             FruitBox& limes);
};

#endif /* defined(__piscine_cpp_d14m__LittleHand__) */

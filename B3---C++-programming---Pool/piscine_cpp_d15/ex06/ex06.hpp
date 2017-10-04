//
//  ex06.hpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d15_ex06_hpp
#define piscine_cpp_d15_ex06_hpp

#include <sstream>
#include <string>
#include <iostream>

template <typename T, typename U=T>
struct  Tuple {
public:
    T a;
    U b;

    template <typename X>
    std::string oklm(X& A) {
        (void)A;
        return std::string("[???]");
    }

    std::string oklm(int& A){
        std::ostringstream easyLife;
        easyLife << A;
        return std::string("[int:" + easyLife.str() + "]");
    }
    std::string oklm(float& A){
        std::ostringstream easyLife;
        easyLife << A;
        return std::string("[float:" + easyLife.str() + "]");
    }
    std::string oklm(std::string& A)
{
      return std::string("[string:\"" + A + "\"]");
    }
    std::string const toString() {
        std::string res;

        res = "[TUPLE " + oklm(a) + " " + oklm(b) + "]";
        return res;
    }
};

#endif

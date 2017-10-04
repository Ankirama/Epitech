//
//  ex01.hpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d15_ex01_hpp
#define piscine_cpp_d15_ex01_hpp

#include <cstring>

template <typename T>
int compare(T const& A, T const& B) {
    if (A > B)
        return 1;
    else
        return A < B ? -1 : 0;
}

template <>
int compare(char const* const& A, char const* const& B) {
    int res;
    
    res = std::strcmp(A, B);
    if (res > 0) {
        return 1;
    }
    else
        return res < 0 ? -1 : 0;
}

template <typename T1, typename T2>
int compare(const T1& A, const T2& B) {
    int res;
    
    res = std::strcmp(A, B);
    if (res > 0)
        return 1;
    else
        return res < 0 ? -1 : 0;
}

#endif

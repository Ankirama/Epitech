//
//  ex02.hpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d15_ex02_hpp
#define piscine_cpp_d15_ex02_hpp

#include <iostream>

template    <typename T>
T min(T const& A, T const& B) {
    std::cout << "template min" << std::endl;
    return A <= B ? A : B;
}

int min(int const& A, int const& B) {
    std::cout << "non-template min" << std::endl;
    return A <= B ? A : B;
}

template <typename T>
T templateMin(T *A, int const size) {
    T mini = A[0];
    int i = 0;
    while (++i < size)
        mini = min<T>(A[i], mini);
    return mini;
}

int nonTemplateMin(int * A, int const size) {
    int mini = A[0];
    int i = 0;
    while (++i < size)
        mini = min(A[i], mini);
    return mini;
}

#endif

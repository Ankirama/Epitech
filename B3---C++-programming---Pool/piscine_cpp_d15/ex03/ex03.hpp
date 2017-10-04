//
//  ex03.hpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d15_ex03_hpp
#define piscine_cpp_d15_ex03_hpp

template <typename T>
void foreach(T *A, void (&func)(const T& elem), int size) {
    for (int i = 0; i < size; ++i) {
        func(A[i]);
    }
}

template <typename T>
void print(const T &A) {
    std::cout << A << std::endl;
}

#endif

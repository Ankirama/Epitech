//
//  ex00.hpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d15_ex00_hpp
#define piscine_cpp_d15_ex00_hpp

template <typename T>
void swap(T &A, T &B) {
    T tmp;
    tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
const T& min(T const& A, T const& B) {
    return A < B ? A : B;
}

template <typename T>
const T& max(T const& A, T const& B) {
    return A > B ? A : B;
}

template <typename T>
T add(T const& A, T const& B) {
    return A + B;
}

#endif

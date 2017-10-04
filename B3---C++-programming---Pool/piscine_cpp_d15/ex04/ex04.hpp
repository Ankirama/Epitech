//
//  ex04.hpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d15_ex04_hpp
#define piscine_cpp_d15_ex04_hpp

template <typename T>
bool equal(T const& A, T const& B);

template <typename T>
class Tester {
public:
    Tester();
    ~Tester();
    bool equal(T const&, T const&);
};

#endif

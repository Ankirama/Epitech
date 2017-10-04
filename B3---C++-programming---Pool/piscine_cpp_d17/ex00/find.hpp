//
//  find.hpp
//  piscine_cpp_d17
//
//  Created by Fabien Martinez on 23/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d17_find_hpp
#define piscine_cpp_d17_find_hpp

#include <algorithm>

template <typename T>
typename T::iterator do_find(T& container, int value) {
    return (std::find(container.begin(), container.end(), value));
}

#endif

//
//  Picture.h
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d13__Picture__
#define __piscine_cpp_d13__Picture__

#include <string>

class Picture {
public:
    Picture();
    Picture(const std::string& file);
    
    ~Picture();
    std::string data;
    bool        getPictureFromFile(const std::string& file);
};

#endif /* defined(__piscine_cpp_d13__Picture__) */

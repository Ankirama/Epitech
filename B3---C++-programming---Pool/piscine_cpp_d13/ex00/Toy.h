//
//  Toy.h
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d13__Toy__
#define __piscine_cpp_d13__Toy__

#include <string>
#include "Picture.h"

class Toy {
public:
    typedef enum ToyType {
        BASIC_TOY,
        ALIEN
    }           ToyType;
    
    Toy();
    Toy(ToyType, std::string const&, std::string const&);
    
    ~Toy();
    
    ToyType getType() const;
    std::string const& getName() const;
    std::string const& getAscii() const;
    
    void    setName(std::string const&);
    bool    setAscii(std::string const&);
    
private:
    ToyType m_type;
    std::string m_name;
    Picture m_pic;
};

#endif /* defined(__piscine_cpp_d13__Toy__) */

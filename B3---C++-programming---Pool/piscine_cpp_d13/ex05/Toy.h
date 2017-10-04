//
//  Toy.h
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d13__Toy__
#define __piscine_cpp_d13__Toy__

#include <iostream>
#include <string>
#include "Picture.h"

class Toy {
public:
    typedef enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    }           ToyType;
    
    class   Error {
    public:
        Error();
        typedef enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        }           ErrorType;
        std::string what() const;
        std::string where() const;
        ErrorType type;
    };
    
    Toy();
    Toy(ToyType, std::string const&, std::string const&);
    Toy(Toy const&);
    Toy& operator=(Toy const&);
    ~Toy();
    
    ToyType getType();
    std::string const& getName() const;
    std::string const& getAscii() const;
    Error&   getLastError();
    
    void    setName(std::string const&);
    bool    setAscii(std::string const&);
    
    virtual void    speak(std::string const&);
    virtual bool    speak_es(std::string const&);
    
    Toy& operator<<(std::string const&);
    
protected:
    ToyType m_type;
    std::string m_name;
    Picture m_pic;
    Error   m_error;
};

std::ostream& operator<<(std::ostream&, Toy const&);


#endif /* defined(__piscine_cpp_d13__Toy__) */

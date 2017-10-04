//
//  Sorcerer.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__Sorcerer__
#define __piscine_cpp_d10__Sorcerer__

#include <string>
#include "Victim.hh"

class   Sorcerer {
private:
    std::string const _name;
    std::string const _title;
    
public:
    explicit Sorcerer(std::string const, std::string const);
    ~Sorcerer();
    
    std::string getName() const;
    std::string getTitle() const;
    
    virtual void polymorph(Victim const &) const;
};

std::ostream& operator <<(std::ostream&, Sorcerer const &) ;

#endif /* defined(__piscine_cpp_d10__Sorcerer__) */

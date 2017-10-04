//
//  Droidmemory.h
//  piscine_cpp_d08
//
//  Created by Fabien Martinez on 14/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d08__Droidmemory__
#define __piscine_cpp_d08__Droidmemory__

#include <string>

class DroidMemory {
private:
    size_t  FingerPrint;
    size_t  Exp;
    
public:
    /* Cannonical basic form */
    DroidMemory();
    DroidMemory(DroidMemory const&);
    DroidMemory& operator=(DroidMemory const &);
    ~DroidMemory();
    
    /* get set */
    size_t  getFingerPrint() const;
    void    setFingerPrint(size_t);
    size_t  getExp() const;
    void    setExp(size_t);
    
    /* operator */
    DroidMemory& operator<<(DroidMemory const&);
    DroidMemory& operator>>(DroidMemory&) const;
    DroidMemory& operator+=(DroidMemory const&);
    DroidMemory& operator+=(size_t const&);
    DroidMemory& operator+(DroidMemory const&) const;
    DroidMemory& operator+(size_t const&) const;

};

std::ostream& operator<<(std::ostream& os, DroidMemory const&);

#endif /* defined(__piscine_cpp_d08__Droidmemory__) */

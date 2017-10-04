//
//  Squad.h
//  piscine_cpp_d10
//
//  Created by  on 16/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#ifndef __piscine_cpp_d10__Squad__
#define __piscine_cpp_d10__Squad__

#include <vector>
#include <string>
#include "ISquad.hh"
#include "ISpaceMarine.hh"

class Squad : public ISquad {
private:
    std::vector<ISpaceMarine *> _marines;
    
public:
    Squad();
    Squad(Squad & );
    Squad& operator=(Squad const&);
    virtual ~Squad();
    
    virtual int getCount() const;
    virtual ISpaceMarine* getUnit(int);
    virtual int push(ISpaceMarine*);
};

#endif /* defined(__piscine_cpp_d10__Squad__) */

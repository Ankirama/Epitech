//
//  Box.h
//  cpp_santa
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_santa__Box__
#define __cpp_santa__Box__

#include "Wrap.hh"

class Box : public Wrap {    
public:
    /* constructors */
    Box();
    Box(Box const&);
    Box& operator=(Box const&);
    
    /*destructor */
    virtual ~Box();
    
    /* getter */
    virtual std::string const getTitle() const;
    
    /* virtual mother fucker ! */
    virtual void    wrapMeThat(Object *);
    virtual void    openMe() ;
    virtual void    closeMe();
    
    virtual bool operator!=(Box const&) const;
};

#endif /* defined(__cpp_santa__Box__) */

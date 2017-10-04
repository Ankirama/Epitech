//
//  Wrap.h
//  cpp_santa
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_santa__Wrap__
#define __cpp_santa__Wrap__

#include <iostream>
#include <stdlib.h>
#include "Object.hh"

#define wrapWeight  42

class Wrap : public Object {
protected:
    bool    m_isOpen;
    bool    m_isEmpty;
    bool    m_isWraped;
    Object  *m_object;
public:
    /* constructors */
    Wrap();
    Wrap(t_type);
    Wrap(Wrap const&);
    Wrap& operator=(Wrap const&);
    
    /* destructor */
    virtual ~Wrap();
    
    /* getter setter */
    bool        isEmpty() const;
    bool        isWraped() const;
    bool        isOpen() const;
    Object      *getObject() const;
    virtual const std::string getTitle() const;
    
    /* am I virtual ? */
    virtual void    wrapMeThat(Object *) = 0;
    virtual void    openMe() = 0;
    virtual void    closeMe() = 0;
    virtual void    isTaken();
    
    virtual bool operator!=(Wrap const&) const;
};

#endif /* defined(__cpp_santa__Wrap__) */

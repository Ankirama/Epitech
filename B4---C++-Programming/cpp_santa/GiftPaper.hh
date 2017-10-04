//
//  GiftPaper.h
//  cpp_santa
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_santa__GiftPaper__
#define __cpp_santa__GiftPaper__

#include <string>
#include "Box.hh"
#include "Wrap.hh"
#include "Toy.hh"

class GiftPaper : public Wrap {
private:
    std::string m_pattern;
public:
    /* constructors */
    GiftPaper();
    GiftPaper(GiftPaper const&);
    GiftPaper& operator=(GiftPaper const&);
    
    /* destructor */
    virtual ~GiftPaper();
    
    /* getter setter */
    std::string getPattern() const;
    virtual std::string const getTitle() const;
    
    /* virtuals mother fucker ! */
    virtual void    wrapMeThat(Object *);
    virtual void    openMe();
    virtual void    closeMe();
};

#endif /* defined(__cpp_santa__GiftPaper__) */

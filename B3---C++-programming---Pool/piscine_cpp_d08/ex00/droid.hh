//
//  droid.hh
//  piscine_cpp_d08
//
//  Created by Fabien Martinez on 14/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d08__droid__
#define __piscine_cpp_d08__droid__

#include <string>

class Droid {
private:
    std::string Id;
    size_t Energy;
    size_t const Attack;
    size_t const Toughness;
    std::string *Status;
    
public:
    /* Cannonical basic form */
    Droid(Droid const &);
    Droid();
    Droid(std::string);
    Droid& operator=(Droid const &);
    ~Droid();
    
    /* get set */
    std::string getId() const;
    void        setId(std::string);
    size_t      getEnergy() const;
    void        setEnergy(size_t);
    std::string *getStatus() const;
    void        setStatus(std::string *);
    size_t      getAttack() const;
    size_t      getToughness() const;
    
    /* operators */
    bool operator==(Droid const &) const;
    bool operator!=(Droid const &) const;
    Droid& operator<<(size_t &);
};

std::ostream& operator <<(std::ostream&, Droid const &) ;

#endif /* defined(__piscine_cpp_d08__droid__) */

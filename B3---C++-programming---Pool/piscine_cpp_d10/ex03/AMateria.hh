//
//  AMateria.h
//  piscine_cpp_d10
//
//  Created by  on 16/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#ifndef __piscine_cpp_d10__AMateria__
#define __piscine_cpp_d10__AMateria__

#include <string>
#include "ICharacter.hh"

class AMateria
{
private:
    std::string m_type;
    unsigned int xp_;

public:
    AMateria(std::string const & type);
    AMateria(AMateria const&);
    AMateria& operator=(AMateria const&);
    virtual ~AMateria();
    
    std::string const & getType() const; //Returns the materia type
    unsigned int getXP() const; //Returns the Materia’s XP
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif /* defined(__piscine_cpp_d10__AMateria__) */

//
//  DomesticKoala.h
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d16__DomesticKoala__
#define __piscine_cpp_d16__DomesticKoala__

#include <vector>
#include "KoalaAction.h"

class DomesticKoala {
public:
    explicit DomesticKoala(KoalaAction&); // Main constructor
    ~DomesticKoala(); // You should
    explicit DomesticKoala(const DomesticKoala&); // know that
    DomesticKoala& operator=(const DomesticKoala&); // at the end...
    
    typedef void (KoalaAction::*methodPointer_t)(const std::string&) ; // You have to find how
    // this type is defined
    // as a member function pointer.
    // Retrieves a vector containing all the member function pointers
    std::vector<methodPointer_t> const * getActions(void) const;
    // Sets a member function pointer, linking the character (the command) to the pointer (the action).
    void learnAction(unsigned char, methodPointer_t);
    // Deletes the command.
    void unlearnAction(unsigned char);
    // Executes the action linked to the given command. The string is the parameter given to the member function.
    void doAction(unsigned char, const std::string&);
    // Affects a new KoalaAction class to the domestic Koala.
    // This erases the pointers table.
    void setKoalaAction(KoalaAction&);
private:
    KoalaAction&    m_koalaAction;
    std::vector<methodPointer_t> m_actions;
    std::vector<char>            m_keys;
    
};

#endif /* defined(__piscine_cpp_d16__DomesticKoala__) */

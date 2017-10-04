//
//  Squad.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <stdlib.h>
#include "Squad.hh"

Squad::Squad() : _marines(0){}
Squad::~Squad() {
    int i;
    int size;
    
    i = -1;
    size = (int)this->_marines.size();
    while (++i < size) {
        delete this->_marines[i];
        this->_marines[i] = NULL;
    }
    while (!this->_marines.empty())
        this->_marines.pop_back();

}
Squad::Squad(Squad &squad){
    for (int i = 0; i < squad.getCount(); ++i) {
        this->_marines.push_back(squad.getUnit(i));
    }
}

Squad& Squad::operator=(Squad const& squad) {
    int             i;
    int             size;
    
    if (this != &squad) {
        i = -1;
        size = (int)this->_marines.size();
        while (++i < size) {
            delete this->_marines[i];
            this->_marines[i] = NULL;
        }
        while (!this->_marines.empty())
            this->_marines.pop_back();
    }
    return *this;
}


int Squad::getCount() const {
    return (int)this->_marines.size();
}

ISpaceMarine* Squad::getUnit(int index) {
    if ((int)this->_marines.size() <= index)
        return NULL;
    return this->_marines[index];
}

int Squad::push(ISpaceMarine* marine) {
    int i;
    if (!marine)
        return (int)this->_marines.size();
    i = 0;
    while (i < (int)this->_marines.size() && this->_marines[i] != marine)
        ++i;
    if (i == (int)this->_marines.size())
        this->_marines.push_back(marine);
    return (int)this->_marines.size();
}
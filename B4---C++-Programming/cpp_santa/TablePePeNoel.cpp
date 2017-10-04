//
//  TablePePeNoel.cpp
//  cpp_santa
//
//  Created by Fabien Martinez on 17/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <stdlib.h>
#include "TablePePeNoel.hh"

/* constructor */
TablePePeNoel::TablePePeNoel() {
    this->m_objects.push_back(new Teddy(30, TEDDY, "pink", "HugMe", "Teddy", false));
    this->m_objects.push_back(new LittlePony(14, LITTLE_PONY, "rainbow", "ArcEnCiel", "RainbowDash", true));
    this->m_objects.push_back(new Box());
    this->m_objects.push_back(new Box());
    this->m_objects.push_back(new GiftPaper());
    this->m_objects.push_back(new GiftPaper());
    this->m_nbrObjects = 6;
}

TablePePeNoel::TablePePeNoel(Object *toy1, Object *toy2) {
    this->m_objects.push_back(toy1);
    this->m_objects.push_back(toy1);
    this->m_objects.push_back(new Box());
    this->m_objects.push_back(new Box());
    this->m_objects.push_back(new GiftPaper());
    this->m_objects.push_back(new GiftPaper());
    this->m_nbrObjects = 6;
}

TablePePeNoel::TablePePeNoel(TablePePeNoel const& copy) {
    this->m_nbrObjects =  copy.m_nbrObjects;
    for (int i = 0; i < copy.m_nbrObjects; ++i) {
        this->m_objects.push_back(copy.m_objects[i]);
    }
}

TablePePeNoel& TablePePeNoel::operator=(TablePePeNoel const& copy) {
    if (this != &copy) {
        this->m_nbrObjects = copy.m_nbrObjects;
        for (int i = 0; i < copy.m_nbrObjects; ++i) {
            this->m_objects.push_back(copy.m_objects[i]);
        }
    }
    
    return *this;
}

/* destructor */
TablePePeNoel::~TablePePeNoel(){}

void        TablePePeNoel::Put(Object* obj) {
    this->m_objects.push_back(obj);
}

Object      *TablePePeNoel::Take(Object const& obj) {
    int     i;
    Object *tmp;
    
    i = -1;
    while (++i < this->m_nbrObjects && obj != *this->m_objects[i]);
    if (i < this->m_nbrObjects)
    {
        tmp = this->m_objects[i];
        this->m_objects[i] = 0;
        return tmp;
    }
    else
    {
        std::cout << "Diantre ! Impossible de trouver " << obj.getTitle();
        return NULL;
    }
}

std::string *TablePePeNoel::Look() {
    
}

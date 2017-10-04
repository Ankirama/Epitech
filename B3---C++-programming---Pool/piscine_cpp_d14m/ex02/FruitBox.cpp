//
//  FruitBox.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "FruitBox.h"

FruitBox::FruitBox(int size) : m_size(size), m_nbrFruits(0), m_list(0) {}
FruitBox::~FruitBox() {}

int FruitBox::nbFruits() const {return this->m_nbrFruits;}

bool FruitBox::putFruit(Fruit* f) {
    FruitNode   *tmp;
    FruitNode   *elt;
    
    tmp = this->m_list;
    if (this->m_nbrFruits == this->m_size)
        return false;
    while (tmp != 0 && tmp->fruit != f)
        tmp = tmp->next;
    if (tmp != 0)
        return false;
    elt = new FruitNode();
    elt->fruit = f;
    elt->next = 0;
    tmp = this->m_list;
    if (tmp == 0)
        this->m_list = elt;
    else {
        while (tmp != 0 && tmp->next != 0)
            tmp = tmp->next;
        tmp->next = elt;
    }
    ++this->m_nbrFruits;
    return true;
}

Fruit* FruitBox::pickFruit() {
    Fruit* fruit;
    
    fruit = this->m_list ? this->m_list->fruit : 0;
    if (this->m_list) {
        this->m_list = this->m_list->next;
        --this->m_nbrFruits;
    }
    return fruit;
}

FruitNode* FruitBox::head() const{
    return this->m_list;
}
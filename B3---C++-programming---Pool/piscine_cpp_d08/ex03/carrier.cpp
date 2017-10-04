//
//  carrier.cpp
//  piscine_cpp_d08
//
//  Created by Fabien Martinez on 14/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "carrier.hh"

Carrier::Carrier(std::string name) : Id(name), Energy(300), Attack(100), Toughness(90), Speed(0) {
    for (int i = 0; i < 5; ++i) {
        this->Droids[i] = NULL;
    }
}
Carrier::Carrier() : Id(""), Energy(300), Attack(100), Toughness(90), Speed(0) {
    for (int i = 0; i < 5; ++i) {
        this->Droids[i] = NULL;
    }
}

Carrier::~Carrier() {
    for (int i = 0; i < 5; ++i) {
        if (this->Droids[i] != NULL)
        delete this->Droids[i];
    }
}

/* get set */
std::string     Carrier::getId() const{
    return this->Id;
}
void            Carrier::setId(std::string name) {
    this->setId(name);
}
size_t          Carrier::getEnergy() const{
    return this->Energy;
}
void            Carrier::setEnergy(size_t energy) {
    this->Energy = energy;
}
size_t          Carrier::getAttack() const{
    return this->Attack;
}
size_t          Carrier::getToughness() const{
    return  this->Toughness;
}
size_t          Carrier::getSpeed() const{
    return this->Speed;
}

/* operators */
Carrier &Carrier::operator<<(Droid *&droid) {
    int i;
    
    i = -1;
    while (++i < 5 && this->Droids[i]);
    if (i < 5)
        this->Droids[i] = droid;
    droid = NULL;
    this->Speed = i < 5 ? (this->Speed == 0 ? 90 : this->Speed - 10) : this->Speed;
    return *this;
}

Carrier &Carrier::operator~(){
    for (int i = 0; i < 5; ++i) {
        this->Speed = this->Speed == 0 ? 90 : (this->Droids[i] ? this->Speed - 10 : this->Speed);
    }
    return *this;
}

Carrier &Carrier::operator>>(Droid *droid) {
    int i;

    i = -1;
    while (++i < 5 && !this->Droids[i]);
    if (i < 5) {
        droid = this->Droids[i];
        this->Droids[i] = NULL;
    }
    this->Speed = i < 5 ? (this->Speed == 0 ? 0 : this->Speed + 10) : this->Speed;
    return *this;
}

bool    Carrier::operator()(int X, int Y) {
    size_t   cost;
    
    cost = ((X < 0 ? -X : X) + (Y < 0 ? -Y : Y)) * (10 + (10 - (this->Speed % 10)));
    if (this->Energy < cost || this->Speed == 0)
    {
        this->Energy = 0;
        return false;
    }
    this->Energy -= cost;
    return true;
}

Droid   &Carrier::operator[](int pos) const{
    return *this->Droids[pos];
}

Carrier &Carrier::operator<<(size_t &energy) {
    this->Energy += energy;
    this->Energy = this->Energy > 600 ? 600 : this->Energy;
    energy = this->Energy == 600 ? (this->Energy + energy) - 600 : 0;
    return *this;
}

std::ostream &operator<<(std::ostream& os, Carrier const& carrier) {
    os << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        os << "[" << i << "] : ";
        if (!carrier.Droids[i])
            os << "Free" << std::endl;
        else
            os << carrier[i] << std::endl;
    }
    return os;
}

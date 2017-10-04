//
//  DomesticKoala.cpp
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction& copy) : m_koalaAction(copy) {}

DomesticKoala::~DomesticKoala() {}

DomesticKoala::DomesticKoala(const DomesticKoala& copy) : m_koalaAction(copy.m_koalaAction) {
    for (unsigned int i = 0; i < copy.m_actions.size(); ++i) {
        m_actions.push_back(copy.m_actions[i]);
    }
    for (unsigned int i = 0; i < copy.m_keys.size(); ++i) {
        m_keys.push_back(copy.m_keys[i]);
    }
}

DomesticKoala& DomesticKoala::operator=(const DomesticKoala& copy) {
    if (this != &copy) {
        m_koalaAction = copy.m_koalaAction;
        if (!m_keys.empty())
            m_keys.clear();
        if (!m_actions.empty())
            m_actions.clear();
        for (unsigned int i = 0; i < copy.m_actions.size(); ++i) {
            m_actions.push_back(copy.m_actions[i]);
        }
        for (unsigned int i = 0; i < copy.m_keys.size(); ++i) {
            m_keys.push_back(copy.m_keys[i]);
        }
    }
    return *this;
}
void DomesticKoala::learnAction(unsigned char key, methodPointer_t action) {
    m_keys.push_back(key);
    m_actions.push_back(action);
}
void DomesticKoala::unlearnAction(unsigned char thug) {
    unsigned int i = 0;
    while (i < m_keys.size() && m_keys[i] != thug) {
        ++i;
    }
    if (i < m_keys.size()) {
        m_keys.erase(m_keys.begin() + i);
        m_actions.erase(m_actions.begin() + i);
    }
}
void DomesticKoala::doAction(unsigned char thug, const std::string& life) {
    unsigned int i = 0;
    
    while (i < m_keys.size() && m_keys[i] != thug)
        ++i;
    if (i < m_keys.size())
        (m_koalaAction.*m_actions[i])(life);
}
void DomesticKoala::setKoalaAction(KoalaAction& thugLife) {
    m_koalaAction = thugLife;
}

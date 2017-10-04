//
//  Event.h
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d16__Event__
#define __piscine_cpp_d16__Event__

#include <string>

class Event {
public:
    Event(void) : m_time(0), m_name("") {}
    Event(unsigned int time, const std::string& name) : m_time(time), m_name(name) {}
    ~Event(void) {}
    Event(const Event& copy) : m_time(copy.m_time), m_name(copy.m_name) {}
    Event& operator=(const Event& copy) {
        if (this != &copy) {
            m_time = copy.m_time;
            m_name = copy.m_name;
        }
        return *this;
    }
    unsigned int getTime(void) const {return m_time;}
    const std::string& getEvent(void) const {return m_name;}
    void setTime(unsigned int time) {m_time = time;}
    void setEvent(const std::string& name) {m_name = name;}
    
private:
    unsigned int    m_time;
    std::string m_name;
};

#endif /* defined(__piscine_cpp_d16__Event__) */

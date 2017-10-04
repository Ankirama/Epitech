//
//  EventManager.h
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d16__EventManager__
#define __piscine_cpp_d16__EventManager__

#include <iostream>
#include <string>
#include <list>
#include "Event.h"

class EventManager {
public:
    EventManager() : m_currentTime(0){}
    ~EventManager() {}
    EventManager(EventManager const &copy) : m_currentTime(0){
        for (std::list<Event>::const_iterator it = copy.m_list.begin(); it != copy.m_list.end(); ++it) {
            m_list.push_back(*it);
        }
    }
    EventManager& operator=(EventManager const &copy) {
        if (this != &copy) {
            m_currentTime = copy.m_currentTime;
            if (!m_list.empty())
                m_list.clear();
            for (std::list<Event>::const_iterator it = copy.m_list.begin(); it != copy.m_list.end(); ++it) {
                m_list.push_back(*it);
            }
        }
        return *this;
    }
    void addEvent(const Event& event) {
        std::list<Event>::iterator it;
        if (event.getTime() >= m_currentTime) {
            it = m_list.begin();
            while (it != m_list.end() && it->getTime() <= event.getTime())
                ++it;
            m_list.insert(it, event);
        }
    }
    void removeEventsAt(unsigned int time) {
        std::list<Event>::iterator it;
        if (!m_list.empty()) {
            it = m_list.begin();
            while (it != m_list.end() && it->getTime() != time)
                ++it;
            if (it != m_list.end() && it->getTime() == time) {
                while (it != m_list.end() && it->getTime() == time) {
                    it = m_list.erase(it);
                }
            }
        }
    }
    void dumpEvents(void) const {
        for (std::list<Event>::const_iterator it = m_list.begin(); it != m_list.end(); ++it) {
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        }
    }
    void dumpEventAt(unsigned int time) const {
        for (std::list<Event>::const_iterator it = m_list.begin(); it != m_list.end(); ++it) {
            if (it->getTime() == time)
                std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        }
    }
    void addTime(unsigned int time) {
        std::list<Event>::iterator it;
        it = m_list.begin();
        m_currentTime += time;
        while (it != m_list.end() && it->getTime() <= m_currentTime) {
            std::cout << it->getEvent() << std::endl;
            it = m_list.erase(it);
        }
    }
    void addEventList(std::list<Event>& list) {
        std::list<Event>::const_iterator it = list.begin();
        while (it != list.end()) {
            if (it->getTime() >= m_currentTime) {
                std::list<Event>::iterator thug = m_list.begin();
                while (thug != m_list.end() && thug->getTime() <= it->getTime())
                    ++thug;
                m_list.insert(thug, *it);
                }
            ++it;
        }
    }
private:
    unsigned int m_currentTime;
    std::list<Event> m_list;
};
#endif /* defined(__piscine_cpp_d16__EventManager__) */

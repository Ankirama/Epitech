//
//  OneTime.h
//  piscine_cpp_d17
//
//  Created by Fabien Martinez on 23/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d17__OneTime__
#define __piscine_cpp_d17__OneTime__

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

//shlag mode enabled
class OneTime : public IEncryptionMethod {
public:
    OneTime(std::string const& key) : m_key(key), m_position(0){}
    virtual ~OneTime() {}
    // Encode the given character, and display it.
    void encryptChar(char plainchar) {
        int res = plainchar;
        char curr = m_key[m_position] <= 'Z' ? m_key[m_position] - 'A' : m_key[m_position] - 'a';
        
        if (plainchar >= 'A' && plainchar <= 'Z') {
            res = (plainchar - 'A') + curr;
            res = res > 0 ? res : -res;
            if (res > 25)
                res = res - 26;
            res += 'A';
        }
        else if (plainchar >= 'a' && plainchar <= 'z') {
            res = (plainchar - 'a') + curr;
            res = res > 0 ? res : -res;
            if (res > 25)
                res = res - 26;
            res += 'a';
        }
        std::cout << (char)res;
        m_position = m_position + 1 == m_key.length() ? 0 : m_position + 1;
    }
    // Decode the given character, and display it.
    void decryptChar(char cipherchar) {
        int res = cipherchar;
        char curr = m_key[m_position] <= 'Z' ? m_key[m_position] - 'A' : m_key[m_position] - 'a';
        
        if (cipherchar >= 'A' && cipherchar <= 'Z') {
            res = (cipherchar - 'A') - curr;
            if (res < 0)
                res = res + 26;
            res += 'A';
        }
        else if (cipherchar >= 'a' && cipherchar <= 'z') {
            res = (cipherchar - 'a') - curr;
            if (res < 0)
                res = res + 26;
            res += 'a';
        }
        std::cout << (char)res;
        m_position = m_position + 1 == m_key.length() ? 0 : m_position + 1;
    }
    // Resets the internal values to their initial state.
    void reset() {m_position = 0;}
private:
    std::string const&  m_key;
    unsigned int        m_position;
};

#endif /* defined(__piscine_cpp_d17__OneTime__) */

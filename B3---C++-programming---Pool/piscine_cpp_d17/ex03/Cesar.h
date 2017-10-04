//
//  Cesar.h
//  piscine_cpp_d17
//
//  Created by Fabien Martinez on 23/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d17__Cesar__
#define __piscine_cpp_d17__Cesar__

#include <iostream>
#include "IEncryptionMethod.h"

//thugLife was here
class Cesar : public IEncryptionMethod{
public:
    Cesar() : m_encode(3) {}
    virtual ~Cesar() {}
    
    // Encode the given character, and display it.
    void encryptChar(char plainchar) {
        int tmp = m_encode % 26;
        if ((plainchar >= 'A' && plainchar <= 'Z')) {
            if (plainchar + tmp > 'Z') {
                tmp = ('Z' - plainchar) - tmp;
                tmp = tmp < 0 ? -tmp : tmp;
                plainchar = 'A' + tmp - 1;
            }
            else
                plainchar += tmp;
        }
        else if ((plainchar >= 'a' && plainchar <= 'z')) {
            if (plainchar + tmp > 'z') {
                tmp = ('z' - plainchar) - tmp;
                tmp = tmp < 0 ? -tmp : tmp;
                plainchar = 'a' + tmp - 1;
            }
            else
                plainchar += tmp;
        }
        
        std::cout << plainchar;
        ++m_encode;
    }
    // Decode the given character, and display it.
    void decryptChar(char cipherchar) {
        int tmp = m_encode % 26;
        if ((cipherchar >= 'A' && cipherchar <= 'Z')) {
            if (cipherchar - tmp < 'A') {
                tmp = tmp - (cipherchar - 'A');
                tmp = tmp < 0 ? tmp * -1 : tmp;
                cipherchar = 'Z' - tmp + 1;
            }
            else
                cipherchar -= tmp;
        }
        else if ((cipherchar >= 'a' && cipherchar <= 'z')) {
            if (cipherchar - tmp < 'a') {
                tmp = tmp - (cipherchar - 'a');
                tmp = tmp < 0 ? tmp * -1 : tmp;
                cipherchar = 'z' - tmp + 1;
            }
            else
                cipherchar -= tmp;
        }
        
        std::cout << cipherchar;
        ++m_encode;
    }
    // Resets the internal values to their initial state.
    void reset() {m_encode = 3;}
private:
    int m_encode;
};

#endif /* defined(__piscine_cpp_d17__Cesar__) */

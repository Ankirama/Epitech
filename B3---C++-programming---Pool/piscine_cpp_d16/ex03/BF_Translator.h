//
//  BF_Translator.h
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d16__BF_Translator__
#define __piscine_cpp_d16__BF_Translator__

#include <string>
#include <map>

class BF_Translator {
public:
    BF_Translator();
    ~BF_Translator();
    int     translate(std::string in, std::string out);
private:
    std::string *m_data; // 60.000 size
    unsigned int m_position; // point to 0 first
    std::map<unsigned int, unsigned int> m_bracketPlace; //allow us to set position for []
    std::map<char><void (*thug)(void)> m_thugLife; //functionPointer tamere
    void thugRead(); // write into file
    void thugWrite();  // std::cin coco (t'as le look coco)
    void thugIncr(); //increase value
    void thugDecr(); //decrease value
    void thugMvUp(); //move up pointer
    void thugMvDw(); //move down pointer
};

#endif /* defined(__piscine_cpp_d16__BF_Translator__) */

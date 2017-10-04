//
//  Parser.h
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d16__Parser__
#define __piscine_cpp_d16__Parser__

#include <stack>
#include <string>

class Parser {
public:
    Parser();
    ~Parser();
    
    void feed(std::string const&);
    int result() const;
    void reset();
private:
    std::stack<char>    m_operators;
    std::stack<int>     m_operands;
};

#endif /* defined(__piscine_cpp_d16__Parser__) */

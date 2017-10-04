//
//  Parser.cpp
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Parser.h"

Parser::Parser() {}
Parser::~Parser() {}

static int _plus(int a, int b) {return a + b;}
static int _minus(int a, int b) {return a - b;}
static int _mult(int a, int b) {return a * b;}
static int _div(int a, int b) {return a / b;}
static int _mod(int a, int b) {return a % b;}

static int _doMyOp(int a, int b, char op) {
    switch (op) {
        case '+':
            return _plus(a, b);
            break;
        case '-':
            return _minus(a, b);
            break;
        case '/':
            return _div(a, b);
            break;
        case '*':
            return _mult(a, b);
            break;
        default:
            return _mod(a, b);
            break;
        }
}

void Parser::feed(std::string const& ope) {
    int i;
    int nb1;
    int nb2;
    char op;
    
    i = 0;
    while (ope[i]) {
        if (ope[i] >= '0' && ope[i] <= '9') {
            int tmp = 0;
            while (ope[i] && ope[i] >= '0' && ope[i] <= '9') {
                tmp = tmp * 10 + ope[i] - '0';
                ++i;
            }
            m_operands.push(tmp);
        }
        else if (ope[i] == ')') {
            nb2 = m_operands.top();
            m_operands.pop();
            nb1 = m_operands.top();
            m_operands.pop();
            op = m_operators.top();
            m_operators.pop();
            m_operands.push(_doMyOp(nb1, nb2, op));
            ++i;
        }
        else if (ope[i] == '+' || ope[i] == '-' || ope[i] == '/' || ope[i] == '*' || ope[i] == '%'){
            m_operators.push(ope[i]);
            ++i;
        }
        else
            ++i;
    }
    nb1 = m_operands.top();
    m_operands.pop();
    if (!m_operands.empty()) {
        if (!m_operators.empty()) {
            op = m_operators.top();
            m_operators.pop();
            nb1 = _doMyOp(nb1, m_operands.top(), op);
        }
        else {
            nb1 += m_operands.top();
            m_operands.pop();
        }
    }
    m_operands.push(nb1);
}

int Parser::result() const {
    return m_operands.top();
}
void Parser::reset() {
    while (!m_operands.empty())
        m_operands.pop();
    while (!m_operators.empty())
        m_operators.pop();
}
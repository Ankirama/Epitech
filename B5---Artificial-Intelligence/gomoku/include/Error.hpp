//
// Created by doT on 15/10/2015.
//

#ifndef GOMOKU_ERROR_HPP
#define GOMOKU_ERROR_HPP

#include <string>
#include <exception>

class	ErrorGomoku : public std::exception {
public:
    ErrorGomoku(std::string const &message, std::string const &component = "Unknown"):
            m_component(component), m_message(message) {}
    virtual ~ErrorGomoku() throw() {}

    std::string const	&getComponent() const {return this->m_component;}
    const char		*what() const throw() {return this->m_message.c_str();}

protected:
    std::string		m_component;
    std::string		m_message;
};

#endif //GOMOKU_ERROR_HPP

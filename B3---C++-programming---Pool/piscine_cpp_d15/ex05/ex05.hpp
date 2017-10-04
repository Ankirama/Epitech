//
//  ex05.hpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef piscine_cpp_d15_ex05_hpp
#define piscine_cpp_d15_ex05_hpp

#include <exception>
#include <iostream>

template <typename T>
class array {
public:
    array() : m_array(0), m_size(0) {}
    array(unsigned int n) : m_array(new T[n]), m_size(n) {}
    array(array const& copy) : m_array(new T[copy.m_size]), m_size(copy.m_size) {
        for (unsigned int i = 0; i < copy.m_size; ++i) {
            m_array[i] = copy.m_array[i];
        }
    }
    array& operator=(array const& copy) {
        if (this != &copy) {
            if (m_array)
                delete []m_array;
            m_array = new T[copy.m_size];
            for (unsigned int i = 0; i < copy.m_size; ++i) {
                m_array[i] = copy.m_array[i];
            }
            m_size = copy.m_size;
        }
        return *this;
    }

    //dump -> const
    void dump() const {
        std::cout << "[";
        for (unsigned int i = 0; i < m_size; ++i) {
            std::cout << m_array[i];
            if (i + 1 < m_size)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    T& operator[](const unsigned int& i){
        T* tmp;

        try {
            if (i >= m_size) {
                tmp = new T[i + 1];
                for (unsigned int j = 0; j < m_size; ++j) {
                    tmp[j] = m_array[j];
                }
                delete [] m_array;
                m_array = tmp;
		delete [] tmp;
                m_size = i + 1;
            }
            return m_array[i];
        }
        catch(...) {
            throw std::exception();
        }
    }
    T& operator[](const unsigned int& i) const{
        if (i >= m_size)
            throw std::exception();
        return m_array[i];
    }

    template<typename U>
    array<U> const& convertTo(U (*conv)(T const& var)) {
        array<U> *abruti = new array<U>(m_size);
        for (unsigned int i = 0; i < m_size; ++i) {
            (*abruti)[i] = conv(m_array[i]);
        }
        return *abruti;
    }

    unsigned int size() const {return m_size;}

    ~array() {if (m_array) delete [] m_array;}
private:
    T* m_array;
    unsigned int m_size;
};

template<> void array<bool>::dump() const{
    std::cout << "[";
    for (unsigned int i = 0; i < m_size; ++i) {
        if (m_array[i] == false) {
            std::cout << "false";
        }
        else
            std::cout << "true";
        if (i + 1 < m_size)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

#endif

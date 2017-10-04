//
//  ProducterStream.cpp
//  PYjour00
//
//  Created by Fabien Martinez on 14/09/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "ProducterStream.hpp"

ProducterStream::ProducterStream() : m_cin(std::cin){
    this->m_typeFlux = NONE;
    this->m_file = 0;
}

ProducterStream::~ProducterStream() {
    if (this->m_file) {
        this->m_file->close();
    }
}

std::string ProducterStream::nextString() {
    switch (this->m_typeFlux) {
        case FILE_FLUX:
            this->m_stream.clear();
            if (!std::getline(*this->m_file, this->m_stream))
                throw std::exception();
            break;
        case STDIN_FLUX:
            this->m_stream.clear();
            if (!std::getline(this->m_cin, this->m_stream))
                throw std::exception();
            break;
        default:
            throw std::exception();
            break;
    }
    
    return this->m_stream;
}

bool        ProducterStream::loadFile(char *path) {
    this->m_file = new std::ifstream(path);
    
    if (!this->m_file->is_open())
        return false;
    else
        this->m_typeFlux = FILE_FLUX;
        return true;
}

bool        ProducterStream::loadStdin() {
    if (this->m_file)
        delete this->m_file;
    this->m_typeFlux = STDIN_FLUX;

    return true;
}

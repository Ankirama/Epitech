//
//  ProducterStream.h
//  PYjour00
//
//  Created by Fabien Martinez on 14/09/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __PYjour00__ProducterStream__
#define __PYjour00__ProducterStream__

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

typedef enum {
    FILE_FLUX,
    STDIN_FLUX,
    NONE
} typeFlux;

class ProducterStream {
public:
    /**
     * @brief: canonical form
     */
    explicit ProducterStream();
    ~ProducterStream();
    
    std::string nextString();
    bool        loadFile(char *path);
    bool        loadStdin();
    
private:
    std::string     m_stream; /**< A changer */
    std::ifstream   *m_file; /**< */
    typeFlux        m_typeFlux; /**< */
    std::istream    &m_cin;
};

#endif /* defined(__PYjour00__ProducterStream__) */

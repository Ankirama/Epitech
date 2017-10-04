//
//  Picture.cpp
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <fstream>
#include "Picture.h"

Picture::Picture() : data(""){}
Picture::Picture(const std::string& file) {
    std::ifstream is(file.c_str());
    std::string tmp;
    if (is) {
        this->data = "";
        while (getline(is, tmp, '\0'))
            this->data += tmp;
        is.close();
    }
    else
        this->data = "ERROR";
}

Picture::~Picture() {}

bool Picture::getPictureFromFile(const std::string& file) {
    std::ifstream is(file.c_str());
    std::string tmp;
    if (is) {
        this->data = "";
        while (getline(is, tmp, '\0'))
            this->data += tmp;
        is.close();
        return true;
    }
    else {
        this->data = "ERROR";
        return false;
    }
}

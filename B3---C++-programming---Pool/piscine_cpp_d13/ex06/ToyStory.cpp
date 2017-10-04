//
//  ToyStory.cpp
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "ToyStory.h"

void ToyStory::tellMeAStory(std::string const& file, Toy& toy1, bool (Toy::*func1)(std::string), Toy& toy2, bool (Toy::*func2)(std::string)) {
    std::ifstream is(file.c_str());
    bool isToy1Turn = true;
    bool error = false;
    Toy::Error e;
    std::string line;
    
    if (is) {
		std::cout << toy1.getAscii() << std::endl;
		std::cout << toy2.getAscii() << std::endl;
        while (!error && getline(is, line)) {
            if (isToy1Turn) {
                if (line.find("picture:", 0) == 0) {
                    if (!toy1.setAscii(line.substr(8))) {
                        error = true;
                        e = toy1.getLastError();
                        std::cout << e.where() << ": " << e.what() << std::endl;
                    }
                    else {
						std::cout << toy1.getAscii() << std::endl;
                    }
                    isToy1Turn = !isToy1Turn;
                }
                else {
                    if (!(toy1.*func1)(line)) {
                        error = true;
                        e = toy1.getLastError();
                        std::cout << e.where() << ": " << e.what() << std::endl;
                    }
                }
            }
            else {
                if (line.find("picture:", 0) == 0) {
                    if (!toy2.setAscii(line.substr(8))) {
                        error = true;
                        e = toy2.getLastError();
                        std::cout << e.where() << ": " << e.what() << std::endl;
                    }
                    else
						std::cout << toy2.getAscii() << std::endl;
                    isToy1Turn = !isToy1Turn;
                }
                else {
                    if (!(toy2.*func2)(line)) {
                        error = true;
                        e = toy2.getLastError();
                        std::cout << e.where() << ": " << e.what() << std::endl;
                    }
                }
            }
            isToy1Turn = !isToy1Turn;
        }
    }
    else
        std::cout << "Bad Story" << std::endl;
}
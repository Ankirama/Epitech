//
// Created by ankirama on 1/14/2016.
//

#ifndef INC_309POLLUTION_PARSING_HH
#define INC_309POLLUTION_PARSING_HH

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "templateString.hh"

class Parsing {
public:
    Parsing(char **argv);
    ~Parsing();

    int                             getN() const { return this->_n; }
    float                           getX() const { return this->_x; }
    float                           getY() const { return this->_y; }
    std::vector<std::vector<int> >  getCSVRes() const { return this->_csvRes; }

    void            parseFile();

private:
    std::vector<int> split(std::string str, char delimiter) {
        std::vector<int> tmp;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            int tok = StringToNumber<int>(token);
            if (tok < 0) {
                std::cerr << "CSV WRONG" << std::endl;
                exit(84);
            }
            tmp.push_back(tok);
        }
        if (tmp.size() != 3) {
            std::cerr << "LINE CSV TOO BIG / SMALL" << std::endl;
            exit(84);
        }
        return tmp;
    }
private:
    int                 _n;
    float               _x;
    float               _y;
    std::string         _file;
    std::vector<std::vector<int> >    _csvRes;
};


#endif //INC_309POLLUTION_PARSING_HH

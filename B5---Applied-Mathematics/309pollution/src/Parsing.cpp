//
// Created by ankirama on 1/14/2016.
//

#include "Parsing.hh"

Parsing::Parsing(char **argv) {
    if (std::string(argv[1]).find('.') != std::string::npos) {
        std::cerr << "n MUST BE A INT" << std::endl;
    }
    this->_n = StringToNumber<int>(std::string(argv[1]));
    this->_file = std::string(argv[2]);
    this->_x = StringToNumber<float>(std::string(argv[3]));
    this->_y = StringToNumber<float>(std::string(argv[4]));
    if (this->_n < 0 || (this->_x < 0 || this->_x > this->_n) || (this->_y < 0 || this->_y > this->_n)) {
        std::cerr << "BAD PARAMETER (n, x, y)" << std::endl;
        exit(84);
    }
}

Parsing::~Parsing() { }

void Parsing::parseFile() {
    std::string line;
    std::ifstream file(this->_file);

    if (file.is_open()) {
        while (std::getline(file, line)) {
            this->_csvRes.push_back(this->split(line, ';'));
        }
        file.close();
    } else {
        std::cerr << "UNABLE TO OPEN CSV" << std::endl;
        exit(84);
    }
}

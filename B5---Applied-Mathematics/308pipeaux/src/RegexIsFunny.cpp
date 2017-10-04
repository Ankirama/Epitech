//
// Created by ankirama on 12/10/2015.
//

#include "RegexIsFunny.hh"

RegexIsFunny::RegexIsFunny() {
}

float RegexIsFunny::checkRayon(std::string number) {
    float nbr = StringToNumber<float>(number);
    if (nbr <= 0) exit(84);
    else return nbr;
}

int RegexIsFunny::checkNumber(std::string number) {
    int nbr = StringToNumber<int>(number);
    if (nbr <= 0) exit(84);
    else return nbr;
}

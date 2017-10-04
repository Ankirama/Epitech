//
// Created by ankirama on 12/10/2015.
//

#include "RegexIsFunny.hh"

RegexIsFunny::RegexIsFunny() {
}

float RegexIsFunny::checkQuantity(std::string number) {
    float nbr = StringToNumber<float>(number);
    if (nbr < 0) exit(84);
    else return nbr;
}

int RegexIsFunny::checkPrice(std::string number) {
    float nbr = StringToNumber<float>(number);
    float tmp = StringToNumber<float>(number);
    if (nbr < 0 || (float)nbr != tmp) exit(84);
    else return nbr;
}

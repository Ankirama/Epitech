#include <iostream>
#include "RegexIsFunny.hh"
#include "Simplex.hh"

#define CHECK_ARGS(ARGS)    (ARGS == 10)

int main(int args, char **argv) {
    RegexIsFunny *regexTest = new RegexIsFunny();
    float quantity[4];
    float price[5];

    if (!CHECK_ARGS(args)) {
        std::cerr << "NOT ENOUGH ARGS" << std::endl;
        exit (84);
    }

    for (int i = 1; i < 5; ++i) {
        quantity[i - 1] = regexTest->checkQuantity(argv[i]);
    }

    for (int i = 5; i < 10; ++i) {
        price[i - 5] = regexTest->checkPrice(argv[i]);
    }

    Simplex toto(price, quantity);
    toto.algorithm();
    toto.display_result(price);
    delete regexTest;
    
    return 0;
}

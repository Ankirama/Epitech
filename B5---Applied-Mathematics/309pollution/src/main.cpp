#include <iostream>
#include "Parsing.hh"
#include "Bezier.hh"

#define CHECK_ARGS(ARGS)    (ARGS == 5)

int main(int argc, char **argv) {
    Parsing	*parsing;
    Bezier	*bezier;
    if (!CHECK_ARGS(argc)) {
        std::cerr <<"NOT ENOUGH ARGS" << std::endl;
        return 84;
    }
    parsing = new Parsing(argv);
    parsing->parseFile();
    bezier = new Bezier(parsing->getN(), parsing->getX(), parsing->getY(), parsing->getCSVRes());
    bezier->algorithm();
    delete parsing;
    return 0;
}

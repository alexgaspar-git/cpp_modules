#include "RPN.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "Usage: ./RPN \"x y [operator]\"" << std::endl;
        return 1;
    }

    RPN rpn;

    try {
        rpn.execRPN(argv[1]);
        std::cout << rpn.getResult() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 2;
    }

    return 0;
}